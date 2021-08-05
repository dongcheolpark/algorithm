<template>
	<div class="box" v-bind:style="{ width : width + 'px', height : height + 'px'}"> </div>
</template>

<script>
export default {
	props : {
		height : Number,
		width : Number,
	}
};
</script>

<style scoped>

.box { 
	display: inline-block;
	background: #AFEEEE;
	margin : 1px #fff;
}

</style>
