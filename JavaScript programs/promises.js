/* 
    async/await vs callback hell
    Sometimes Nested Callback hell becomes a headache whereas async/await keeps it synchronous and
    easy to read code.
*/

const getEmployeeId = param => new Promise((resolve, reject) => {
    if(param) {
        const id = Math.ceil(Math.random() * 100 + 1)
        resolve(id)
    }
    reject("Param is missing")
})

// Using Callback
getEmployeeId().then(response => {
    console.log(`Response: `, response)
}).catch(error => {
    console.log(`Error: `, error)
})

// using async/await
const callFunc = async () => {
    try {
        const id = await getEmployeeId()
        console.log(`Generated Id: `, id)
    }
    catch(error) {
        console.log(`async/await Error: `, error)
    }
}

callFunc()