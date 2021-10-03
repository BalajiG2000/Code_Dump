let container = document.querySelector('.container')
let butt = document.querySelector('a')



document.addEventListener('DOMContentLoaded',()=>{

 document.querySelector('p').innerHTML = 'Click the button'
 document.querySelector('a').innerHTML = 'Random Color'
})

const validChars = '0123456789ABCDEF'
const hexo = 6

function randomIntFromInterval(min,max){
    return Math.floor(Math.random()*(max-min+1)+min)

}
   
function getcolor(){
    let color = '#'
    for(let i =1;i<=6;i++){
        let randchar = validChars.charAt(randomIntFromInterval(0,15)

        )
        color += randchar
    }
    
 document.querySelector('p').innerHTML =color
 container.style.backgroundColor = color
}




  
  butt.addEventListener('click',()=>{
    document.querySelector('a').innerHTML = 'Next Random Color'
    getcolor()
    


 
})

