<template>
	<div class="box" v-bind:style="{ width : width + 'px', height : height + 'px'}"> </div>
</template>

<script>
export default {
	data() {
		return {
			width : 10,
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
	background: #AFEEEE;
	margin: 1px;
}

</style>
