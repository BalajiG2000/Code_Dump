let fieldsObject = {
    event: "Hacktober",
    duration: "1 Month",
    type: "Open Source",
    description: "Hacktoberfest is a celebration open to everyone in our global community."
}

/*
    To check if all fields exist in object or not
*/

function checkIfAllFieldsExist(object = {}, requiredFields = []) {
    return [...requiredFields].every(p => object.hasOwnProperty(p))
}

// return true as all fields exist
checkIfAllFieldsExist(fieldsObject, ["event", "duration", "type", "description"])

// return false as "event" key is missing
checkIfAllFieldsExist(fieldsObject, ["event", "duration", "type", "description", "event"])
