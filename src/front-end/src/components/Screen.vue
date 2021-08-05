<template>
  <div class="box">
    <div class="graph">
      <box :height="i*10" v-for="i in list[0]" :key="{i}"/>
    </div>
  </div>
</template>
<script>
import Box from './Box.vue';
import axios from 'axios';

export default {
  name :"Screen",
  data() {
    return {
      list : [[1,2,3,4,5]]
    };
  },
  created() {
    axios.get('http://localhost:8000/sort/?size=15&type=1')
      .then((Response)=>{
        this.list = Response.data.data;
      })
      .catch(e => {
        console.log(e);
      })
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