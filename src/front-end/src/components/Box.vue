<template>
	<div class="box" v-bind:style="{ width : width + 'px', height : height + 'px'}"> </div>
</template>

<script>
export default {
	data() {
		return {
			width : 40,
		};
	},
	props : {
		height : String
	}
};
</script>

<style scoped>

.box { 
	display: inline-block;
	border : 1px solid #000
}

</style>
