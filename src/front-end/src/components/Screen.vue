<template>
  <div class="box">
    <div class="graph"> 
    </div>
  </div>
</template>
<script>
export default {
  name :"Screen",
  props:{
    msg:String,
  },
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