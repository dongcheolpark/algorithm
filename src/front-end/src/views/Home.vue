<template>
  <div class="home">
    <Screen msg="Welcome to Your Vue.js App" />
    <buttons />
  </div>
</template>

<script>
// @ is an alias to /src
import Screen from "@/components/Screen.vue";
import Buttons from '../components/buttons.vue';

export default {
  name: "Home",
  components: {
    Screen,
    Buttons,
  },
};
</script>
