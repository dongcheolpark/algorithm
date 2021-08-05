<template>
	<div>
		<button v-on:click="clickEvent">click me</button>
	</div>
</template>

<script>
import eventBus from '../assets/eventBus.js';

export default ({
	name : "buttons",
	methods : {
		clickEvent : () => {
			eventBus.$emit('click1');
		}
	}
})
</script>
