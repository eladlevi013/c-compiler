function index(arg->arr:int*;arg->size,element:int):int{
	for(i=0;i<size;i=i+1)
		if(arr[i]==element)
			return i;
	return -1;
}

function main():void{
	var i = index(arr,5,7):int;
}