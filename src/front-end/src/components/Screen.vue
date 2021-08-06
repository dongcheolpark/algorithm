<template>
  <div class="box">
    <div class="graph" ref = "graph">
      <box :height="(i*500/count)" :width="box_width" v-for="i in list[j]" :key="i"/>
    </div>
  </div>
</template>
<script>
import Box from './Box.vue';
import axios from 'axios';
import eventBus from '../assets/eventBus.js';

export default {
  name :"Screen",
  data() {
    return {
      list : [[1,2,3,4,5]],
      count : 0,
      box_width : 0,
      stop : false,
      j : 0
    };
  },
  created() {
    eventBus.$on('load', (data) => {
      this.list = [];
      this.box_width = this.$refs.graph.scrollWidth;
      axios.get(`http://localhost:8000/sort/?size=${data[0]}&type=${data[1]}`)
        .then((Response)=>{
          this.j = 0;
          this.stop = true;
          this.list = Response.data.data;
          this.count = this.list[0].length;
          this.box_width /= this.count+1;
        })
        .catch(e => {
          console.log(e);
        });
    })
    eventBus.$on('click1',async () => {
      if(this.stop == false) return;
      var x = this.range(0,this.list.length);
      this.stop = false;
      var t = 2000/this.list.length;
      console.log(t);
      for(var i in x) {
        if(this.stop) break;
        this.j = i;
        await this.sleep(t);
      }
    })
  },
  mounted() {
    this.$nextTick(() => {
      window.addEventListener('resize',() => {
        this.box_width = this.$refs.graph.scrollWidth;
        this.box_width /= this.count+1;
      })
    })
  },
  methods : {
    sleep : (ms) => {
      return new Promise((r) => setTimeout(r, ms));
    },
    range : (start, end, step=1) => {
      let array = [];
      for (let i = start; i < end; ++i) {
        if (!(i % step)) {
          array.push(i);
        }
      }
      return array;
    }
  },
  props:{
    msg:String,
  },
  components : {
    Box,
  }
};
</script>

<style scoped>
.box {
  text-align: center;
}
.graph {
  display: inline-block;
  width: 80%;
  height:auto;
  outline: black solid 3px;
  margin: 5rem;
}
.graph_bar {
  height: 100%;
}
</style>