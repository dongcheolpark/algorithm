<template>
	<div>
		<button v-on:click="loadEvent" >Loading</button>
		<div>
			<input type="range" min="5" max="100" v-model="size"/>
			<select name="type" id = "type" v-model="type">
				<option value="1">bubble sort</option>
				<option value="2">insert sort</option>
				<option value="3">selection sort</option>
				<option value="4">merge sort</option>
			</select>
		</div>
		<button v-on:click="clickEvent">click me</button>
	</div>
</template>

<script>
import eventBus from '../assets/eventBus.js';

export default {
	name : "buttons",
	data : () => {
		return {
			size : 5,
			type : 1,
		};
	},
	methods : {
		loadEvent() {
			var a = [this.size,this.type];
			eventBus.$emit('load',a);
		},
		clickEvent : () => {
			eventBus.$emit('click1');
		}
	}
}
</script>
