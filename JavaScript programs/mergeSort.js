function mergeSort(array,half = array.length/2){

  if(array.length < 2){
    return array
  }

  const left = array.splice(0,half); 

  return merger(mergeSort(left),mergeSort(array))
}

function merger(left_part,right_part){

  const arr = [];

  while(left_part.length && right_part.length){
    if(left_part[0] < right_part[0]){
      arr.push(left_part.shift())
    }else{
      arr.push(right_part.shift())
    }
  }

  return [...arr,...left_part,...right_part];
}

console.log(mergeSort([2,9,4,1,3,7,3,10,5,6]));
