/*
    Debouncing minimizes the API Call(s) to be made during any input keyup/keydown process
    Here we are using Lodash debounce function
*/
jQuery(function () {
    jQuery("input[name='name']").on("keydown", _.debounce(e => {
        let query = jQuery(e.target).val()
        let regex = new RegExp(query, 'g')
        let filteredData = names.filter(e => regex.test(e))
        jQuery("#listItems").html(filteredData.join(", "))
    }, 500)
    )
})

let names = ["Yoshio", "Finn", "Jared", "Malachi", "Reese", "Wesley", "Keith", "Hasad", "Ashton", "Davis", "Ivan", "Arthur", "Matthew", "Myles", "Caesar", "Cyrus", "Micah", "Todd", "Nolan", "Raja", "Kirk", "Erasmus", "Kane", "Kato", "Phelan", "Hall", "Avram", "Omar", "Neville", "Hop", "Allen", "Cullen", "Arden", "Howard", "Lucius", "Abraham", "Griffin", "Rafael", "Declan", "Wylie", "Herrod", "Troy", "Joseph", "Valentine", "Aquila", "Leo", "Rudyard", "Hedley", "Duncan", "Travis", "Curran", "Nicholas", "Cyrus", "Caldwell", "Wayne", "Merrill", "Jarrod", "Bert", "Beau", "Louis", "Giacomo", "Nicholas", "Oren", "Clarke", "Barrett", "Clinton", "Raja", "Axel", "Tarik", "Kasper", "Nash", "Bevis", "Upton", "Nigel", "Philip", "Adrian", "Reuben", "Plato", "Lev", "Igor", "Nasim", "Lucius", "Hilel", "Abel", "Brian", "Keith", "Blake", "Clinton", "Oscar", "Harlan", "Macon", "Ezra", "Rooney", "Reed", "Dieter", "Quamar", "Mark", "Yuli", "Lewis", "Colin"]