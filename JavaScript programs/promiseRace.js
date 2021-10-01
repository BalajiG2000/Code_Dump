let p1 = new Promise((resolve, reject) => {
    setTimeout(() => resolve("one"), 200);
});

let p2 = new Promise((resolve, reject) => {
    setTimeout(() => resolve("two"), 300);
});

let p3 = new Promise((resolve, reject) => {
    setTimeout(() => resolve("three"), 100);
});

let p4 = new Promise((resolve, reject) => {
    setTimeout(() => reject("four"), 500);
});

let p5 = new Promise((resolve, reject) => {
    setTimeout(() => reject("five"), 100);
});

let p6 = 20;

function race(array) {
    return new Promise((resolve, reject) => {
        array.forEach(async (promise) => {
            try {
                let res = await promise;
                resolve(res);
            } catch (err) {
                reject(err);
            }
        });
    })
}

race([p1, p2, p4, p5]).then(res => console.log(res)).catch(err => console.log(err));
// Output: five
