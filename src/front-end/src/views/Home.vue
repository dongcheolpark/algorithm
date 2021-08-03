<template>
  <div class="home">
    <Screen msg="Welcome to Your Vue.js App" />
  </div>
</template>

<script>
// @ is an alias to /src
import Screen from "@/components/Screen.vue";

export default {
  name: "Home",
  components: {
    Screen,
  },
};
</script>
