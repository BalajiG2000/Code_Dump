const users = [
  {
    "id": 1000,
    "name": "Corey Griffith",
    "age": 13
  },
  {
    "id": 1001,
    "name": "Marion McDaniel",
    "age": 15
  },
  {
    "id": 1002,
    "name": "Tom Robbins",
    "age": 15
  },
  {
    "id": 1003,
    "name": "Ruth Harvey",
    "age": 14
  },
  {
    "id": 1004,
    "name": "Terry Willis",
    "age": 13
  }
]

let lessThan13 = users.filter(user => user.age >= 13)
let moreThan13 = users.filter(user => user.age < 13)

console.log(lessThan13, moreThan13)
