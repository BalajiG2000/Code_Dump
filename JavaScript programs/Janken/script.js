const getComp = () => {
    const comp = Math.random();
    if (comp <= 0.34) return 'fa-hand-rock';
    if (comp >= 0.34 && comp <= 0.67) return 'fa-hand-scissors';
    return 'fa-hand-paper';
}

const result = (player, comp) => {
    if (player == comp) return 'draw';
    if (player == 'fa-hand-rock') return (comp == 'fa-hand-scissors') ? 'win' : 'lose';
    if (player == 'fa-hand-scissors') return (comp == 'fa-hand-paper') ? 'win' : 'lose';
    if (player == 'fa-hand-paper') return (comp == 'fa-hand-rock') ? 'win' : 'lose';
}

const repeat = () => {
    const i = document.querySelector('.rocke');
    const object = ['fa-hand-rock', 'fa-hand-scissors', 'fa-hand-paper'];
    let x = 0;
    const startTime = new Date().getTime();
    setInterval(() => {
        if (new Date().getTime() - startTime > 1000) {
            clearInterval;
            return;
        }
        i.setAttribute('class', `fas ${object[x++]} rocke`);
        if (x == object.length) {
            x = 0;
        }
    }, 100);
}

const btn = document.querySelectorAll('.con-area i');
let win = 1;
let lose = 1;
btn.forEach((i) => {
    i.addEventListener('click', () => {
        const player = i.classList.item(1);
        const comp = getComp();
        const resultB = result(player, comp);

        repeat();

        setTimeout(() => {
            const compDisp = document.querySelector('.rocke');
            compDisp.setAttribute('class', `fas ${comp} rocke`);

            const resDisp = document.querySelector('.result');

            resDisp.innerHTML = `${resultB}`;
            if (resultB == 'win') {
                resDisp.style.color = 'lightblue';
                document.getElementById('score-player').innerHTML = win++;
            } else if (resultB == 'lose') {
                resDisp.style.color = 'salmon';
                document.getElementById('score-comp').innerHTML = lose++;
            } else {
                resDisp.style.color = 'grey';
            }
        }, 1000);

    })

})

const btnRepeat = document.getElementById('repeat');
btnRepeat.addEventListener('click', () => {
    window.location.reload();
})

const btnDark = document.getElementById('dark');
btnDark.addEventListener('click', () => {
    document.body.style.backgroundColor = '#182137';
    document.querySelector('h1').style.color = '#fff';
})