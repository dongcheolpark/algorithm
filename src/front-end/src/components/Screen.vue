<template>
  <div class="box">
    <div class="graph">
      <box v-bind:height="i" v-for="i in list" :key="{i}"/>
    </div>
  </div>
</template>
<script>
import Box from './Box.vue';

export default {
  name :"Screen",
  data() {
    return {
      list : [10,20,30,40,50]
    };
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