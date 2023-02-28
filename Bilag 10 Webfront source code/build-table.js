// Sets the headlines for the table
let keys = ["Package number", "Color", "Weight (g)", "Sorted"];


/* =====================================
    Generate the headlines for the table
====================================== */
function generateTableHead(table, keys) {
    let thead = table;
    thead.createTHead();
    let row = thead.insertRow();
    for (let key of keys) {
        let th = document.createElement("th");
        let text = document.createTextNode(key);
        th.appendChild(text);
        row.appendChild(th);
    }
}

/* ===========================================
    Loads the maximum weight from user sorting
============================================ */
function loadWeight() {
    var weight = document.getElementById("Weight").value;
    if (weight == "") {
        weight = "100000";
    }

    return weight;
}

/* =================================================
    Loads the minimum and maximum from user sorting
================================================== */
function loadColors() {
    var Min = [];
    var Max = [];
    var colors = ["R", "G", "B"];
    for (i = 0; i < 3; i++) {
        Min[i] = parseInt(document.getElementById(colors[i] + "min").value, 10);
        if (isNaN(Min[i])) {
            //DEBUG
            //console.log("Setting " + colors[i] + "min to 0");
            Min[i] = 0;
        }
        Max[i] = parseInt(document.getElementById(colors[i] + "max").value, 10);
        if (isNaN(Max[i])) {
            //DEBUG
            //console.log("Setting " + colors[i] + "max to 255");
            Max[i] = 255;
        }
    }
    //DEBUG
    //console.log(Min);
    //console.log(Max);

    return [Min, Max];
}

/* ==========================================================================
    Checks if the data fits surtain sorting criteria.

    data: Individual package that needs to fit the criteria
    colors: User criteria for color values [min[r, g, b], max[r, g, b]]
    weight: User criteria for maxmimum weight
    sorted: User criteria for sorted

    return false: Dont print the line because it doesnt fit sorting criteria
    return true: Print the line because it fits sorting criteria
=============================================================================*/
function fitsSort(data, colors, weight, sorted) {
    //Sort color
    var color = ["r", "g", "b"];
    for (i = 0; i < colors[0].length; i++) {
        // If smaller than minimum or larger than maximum
        if (data["color"][0][color[i]] < colors[0][i] || data["color"][0][color[i]] > colors[1][i]) {
            //DEBUG
            //console.log(data["color"][0][color[i]]);
            console.log("Color wrong for box: " + data["id"]);
            return false;
        }
    }
    //Sort weight
    if (data["weight"] > weight) {
        //DEBUG
        console.log("Weight wrong for box: " + data["id"]);
        return false;
    }

    //Sort if sorted or not
    switch (sorted) {
        case "all":

            break;
        case "true":
            if (!data["sort"]) {
                return false;
            }
            break;
        case "false":
            if (data["sort"]) {
                return false;
            }
            break;
        default:
            break;
    }
    return true;
}

/* =============================================
    Generates a table from the specific div in the HTML 
    with keys as headlines and data as rows in the tabel
==============================================*/
function generateTable(div, keys, data) {
    let table = document.createElement("table");
    // ====================================== 
    // Only do this if its not the color subtable
    // ======================================== 
    if (keys != "") {
        generateTableHead(table, keys);
        var colorMinMax = loadColors();
        var weightMax = loadWeight();
        var sorted = document.getElementById("sorted").value;
        //DEBUG
        //console.log(colorMinMax);
    }
    // ===================================
    // Delete tabel if it already exists
    // =====================================
    try {
        var x = div.firstElementChild.tagName;
        //DEBUG
        //console.log(div.firstElementChild.tagName);
        if ((x == "H2" || x == "TABLE")) {
            div.firstElementChild.remove();
            console.debug("remove output table");
        }
    } catch (err) {
        console.debug("Couldn't remove table");
    }
    div.appendChild(table);

    // ====================================
    // Start main loop through data
    // ====================================
    //console.log(data);
    for (element in data) {
        //Check if package fits sort
        var elm = data[element];
        //DEBUG
        //console.log(elm);
        //If package doesnt fit the sort, then continue to next package
        if (keys != "" && !fitsSort(elm[0], colorMinMax, weightMax, sorted)) {
            continue;
        }
        let row = table.insertRow();
        //Enter if its the color data and edit the color of the surrounding box
        if (keys == "") {
            row.style.background = "rgb(" + elm["r"] + "," + elm["g"] + "," + elm["b"] + ")";
        } else {
            row.style.borderBottom = "1px solid gray";
            elm = elm[0];
        }
        //DEBUG
        //console.log(element);
        //print the data in the box
        for (key in elm) {
            var myKey = elm[key];
            //DEBUG
            //console.log(myKey);
            //console.log(key);
            //If its color generate a sub table
            if (key == "color") {
                generateTable(row, "", myKey);
            } else {
                let cell = row.insertCell();
                let text = document.createTextNode(myKey);
                cell.appendChild(text);
            }
        }
    }
}

/* ===============================================
    Clears the table at the specific element
    Checks if its already removed
================================================ */
function cleanTable() {
    let temp = document.getElementById("output");
    try {
        if (temp.firstElementChild.tagName == "H2") {

        } else {
            temp.firstChild.remove();
        }
    } catch (err) {
        temp.innerHTML = "<h2>No table to remove</h2>";
    }

    console.log("Cleaned table");
}

/* =========================================
    Used by the button to initialize generation of table
    Loads data into variable and parses it into generateTable function
========================================== */
function updateTable() {
    // Finds the output element where the table will be places
    let table = document.getElementById("output");
    console.log("Generating table");
    // Tries to load the JSON file otherwise throws error in console
    try {
        var json = $.getJSON({
            'url': "./database.json",
            'async': false
        });
    } catch (err) {
        console.log(err)
    }
    //The next line of code will filter out all the unwanted data from the object.
    json = JSON.parse(json.responseText)["data"];
    generateTable(table, keys, json);
}