var newday = document.getElementById("newday");
var btm = document.getElementById("btm");
var list = document.getElementById("list");


btm.addEventListener("click" , function () {
    location.href = '../Website' + newday.value;
})

var ListTitle = ["HomePage", "Make a Deal!", "Panting random Color"];
var Texts = "";
var i;
for (i = 0; i < ListTitle.length; i++){
    Texts += '<dt id = "Website' + parseInt(i + 1, 10)+'"style="color: rgb(218, 127, 8); font-size: 25px;">Day' + parseInt(i + 1, 10) + '</dt>'+
        '<dd style = "font-size: 20px;"><a href = "../Website' +
        parseInt(i + 1, 10) + '">' + ListTitle[i] + '</a></dd>';
    }
var re = document.getElementById("Website_list").innerHTML = Texts;
;
