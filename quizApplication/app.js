//Question bank
var questionBank = [
    {
        question: 'Who is the Founder of Pakistan?',
        option: ['Quaid-e-Azam', 'Liaquat Ali Khan', 'Mahathma Gandhi', 'Allama Iqbal'],
        answer: 'Quaid-e-Azam'
    },
    {
        question: 'Computer is an........',
        option: ['Electronic Device', 'Mechanical Device', 'Portable Device', 'Hand-Held Device'],
        answer: 'Electronic Device'
    },
    {
        question: 'Who is the president of Pakistan?',
        option: ['Imran Khan', 'Arif Alvi', 'Bilawal Bhutto Zardari', 'None of these'],
        answer: 'Arif Alvi'
    },
    {
        question: 'Which player has scored fastest century in an ODI?',
        option: ['Shahid Afridi', 'Chris Gayle', 'Rohit Sharma', 'AB Develiers'],
        answer: 'AB Develiers'
    },
    {
        question: 'First human heart transplant operation conducted by Dr. Christiaan Barnard on Louis Washkansky, was conducted in',
        option: ['1967', '1968', '1958', '1922'],
        answer: '1967'
    }
]

var question = document.getElementById('question');
var quizContainer = document.getElementById('quiz-container');
var scorecard = document.getElementById('scorecard');
var option0 = document.getElementById('option0');
var option1 = document.getElementById('option1');
var option2 = document.getElementById('option2');
var option3 = document.getElementById('option3');
var next = document.querySelector('.next');
var points = document.getElementById('score');
var span = document.querySelectorAll('span');
var i = 0;
var score = 0;

//function to display questions
function displayQuestion() {
    for (var a = 0; a < span.length; a++) {
        span[a].style.background = 'none';
    }
    question.innerHTML = 'Q.' + (i + 1) + ' ' + questionBank[i].question;
    option0.innerHTML = questionBank[i].option[0];
    option1.innerHTML = questionBank[i].option[1];
    option2.innerHTML = questionBank[i].option[2];
    option3.innerHTML = questionBank[i].option[3];
    stat.innerHTML = "Question" + ' ' + (i + 1) + ' ' + 'of' + ' ' + questionBank.length;
}

//function to calculate scores
function calcScore(e) {
    if (e.innerHTML === questionBank[i].answer && score < questionBank.length) {
        score = score + 1;
        document.getElementById(e.id).style.background = 'green';
    }
    else {
        document.getElementById(e.id).style.background = 'red';
    }
    setTimeout(nextQuestion, 200);
}

//function to display next question
function nextQuestion() {
    if (i < questionBank.length - 1) {
        i = i + 1;
        displayQuestion();
    }
    else {
        points.innerHTML = score + '/' + questionBank.length;
        quizContainer.style.display = 'none';
        scoreboard.style.display = 'block'
    }
}

//Back to Quiz button event
function backToQuiz() {
    location.reload();
}

//function to check Answers
function checkAnswer() {
    var answerBank = document.getElementById('answerBank');
    var answers = document.getElementById('answers');
    answerBank.style.display = 'block';
    scoreboard.style.display = 'none';
    for (var a = 0; a < questionBank.length; a++) {
        var list = document.createElement('li');
        list.innerHTML = questionBank[a].answer;
        answers.appendChild(list);
    }
}


displayQuestion();