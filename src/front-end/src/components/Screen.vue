<template>
  <div class="box">
    <div class="graph">
      <box :height="i*10" v-for="i in list[j]" :key="{i}"/>
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
      j : 0
    };
  },
  created() {
    axios.get('http://localhost:8000/sort/?size=100&type=1')
      .then((Response)=>{
        this.list = Response.data.data;
      })
      .catch(e => {
        console.log(e);
      })
    eventBus.$on('click1',async () => {
      var x = this.range(0,this.list.length);
      for(var i in x) {
        this.j = i;
        await this.sleep(10);
      }
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
  height: 30rem;
  outline: black solid 3px;
  margin: 5rem;
}
.graph_bar {
  height: 100%;
}
</style>