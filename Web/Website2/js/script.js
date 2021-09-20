var count_key = 0;


function Click(i) {
    var result = confirm("確定？");
    console.log(i);

    if (result && count_key == 0) {
        alert("Let get start!");
        Choose(i);
        
    }
    else {
        alert("Let watch the story!");
        Story(i);
    }
        
       
}
    


function Choose(i) {
    count_key = i;
    
    switch (i) {
        case 1:
            document.getElementById("title").innerHTML =
                '<h1>Welcome to the Ocean!</h1>' +
                '<h3> choose an animal</h3>' +
                '<h3>then watch its story.</h3>';
            document.body.style.backgroundImage = "url(img/Ocean.jpg)";
            document.body.style.backgroundSize = "cover";
            document.getElementById("Picture1").src = "img/shark.png";
            document.getElementById("Picture2").src = "img/whale.png";
            document.getElementById("Picture3").src = "img/sea turtle.png";
            document.getElementById("Text").innerHTML =
                '<p>Shark</p><p>Whale</p><p>Sea Turtle</p>';
            break;
        case 2:
            document.getElementById("title").innerHTML =
                '<h1>Welcome to the Forest!</h1>' +
                '<h3> choose an animal</h3>' +
                '<h3>then watch its story.</h3>';
            document.body.style.backgroundImage = "url(img/Forest.jpg)";
            document.body.style.backgroundSize = "cover";
            document.getElementById("Picture1").src = "img/monkey.png";
            document.getElementById("Picture2").src = "img/tiger.png";
            document.getElementById("Picture3").src = "img/deer.png";
            document.getElementById("Text").innerHTML =
                '<p>Monkey</p><p>Tiger</p><p>Deer</p>';
            break;
        case 3:
            document.getElementById("title").innerHTML =
                '<h1>Welcome to the Air!</h1>' +
                '<h3> choose an animal</h3>' +
                '<h3>then watch its story.</h3>';
            document.body.style.backgroundImage = "url(img/Air.jpg)";
            document.body.style.backgroundSize = "cover";
            document.getElementById("Picture1").src = "img/owl.png";
            document.getElementById("Picture2").src = "img/Hummingbird.png";
            document.getElementById("Picture3").src = "img/eagle.png";
            document.getElementById("Text").innerHTML =
                '<p>Owl</p><p>Hummingbird</p><p>Eagle</p>';
            break;
    }
}

function Story(i) {
    console.log(count_key, i);
    switch (count_key) {
        case 1:
            switch (i) {
                case 1:
                    document.getElementById("title").innerHTML =
                        '<h1>Welcome to the Shark story!</h1>';
                    document.getElementById("key").innerHTML =
                        '<img  src="img/shark_story.png" height="200px" width="200px">';
                    document.getElementById("Text").innerHTML =
                        '<h2>鯊魚是鯊總目動物的通稱，屬於軟骨魚綱中的板鰓亞綱，至今已經演化出約500個不同的種。' +
                        '鯊魚有高度流線、適合游泳的外型，全身覆滿了盾鱗，' +
                        '並且鯊魚的感覺器官相當靈敏，甚至能嗅出幾公里之外的血腥味。它們具有感應電的能力，並可以此發覺隱藏在沙底下的獵物</h2> ';
                    break;
                case 2:
                    document.getElementById("title").innerHTML =
                        '<h1>Welcome to the Whale story!</h1>';
                    document.getElementById("key").innerHTML =
                        '<img  src="img/whale_story.png" height="200px" width="200px">';
                    document.getElementById("Text").innerHTML =
                        '<h2>是海洋哺乳動物鯨下目中部分生物的通稱。鯨並不屬於魚類，而是哺乳類動物的一種。' +
                        '鯨的嗅覺之發達，可以同時活躍於水上和水下的環境，以至於有的鯨甚至在盲了以後仍能生存。' +
                        '數世紀以來，鯨經常被作為桌上佳餚或是工業產品的原料。</h2> ';
                    break;
                case 3:
                    document.getElementById("title").innerHTML =
                        '<h1>Welcome to the Sea Turtle story!</h1>';
                    document.getElementById("key").innerHTML =
                        '<img  src="img/sea turtle_story.png" height="200px" width="200px">';
                    document.getElementById("Text").innerHTML =
                        '<h2>海龜是海洋龜類的總稱，所有龜鱉目動物中唯一生活在海洋的物種，分布範圍十分廣泛，分布於除北冰洋外的全球海域中。' +
                        '背上有殼，其花紋較一般陸龜或河龜複雜，殼的外型是扁平流線形，腳為船槳狀。' +
                        '海龜喜歡熱帶及溫帶淺海水域，以肺呼吸，產卵時必須回到陸地上，不同海龜的主食都不大相同，多數海龜都是迴游性的，在繁殖季時會從覓食棲地回到產卵棲地。</h2> ';
                    break;
            }
            break;

        case 2:
            switch (i) {
                case 1:
                    document.getElementById("title").innerHTML =
                        '<h1>Welcome to the Monkey story!</h1>';
                    document.getElementById("key").innerHTML =
                        '<img  src="img/monkey_story.png" height="200px" width="200px">';
                    document.getElementById("Text").innerHTML =
                        '<h2>猴，通常用於指稱新世界猴及舊世界猴。新世界猴即"闊鼻小目"；舊世界猴即"猴科"，屬"狹鼻小目"，而這個目也包括猿。' +
                        '猴種類的部分特徵差不多，例如很多新世界猴會有纏卷的尾巴，這樣當牠們爬樹時就可以用來抓著樹枝，相反舊世界猴就沒有纏卷的尾巴，而是有較小的鼻孔。' +
                        '多數猴子是素食者，但其中的狒狒卻會偶然吃肉的。</h2> ';
                    break;
                case 2:
                    document.getElementById("title").innerHTML =
                        '<h1>Welcome to the Tiger story!</h1>';
                    document.getElementById("key").innerHTML =
                        '<img  src="img/tiger_story.png" height="200px" width="200px">';
                    document.getElementById("Text").innerHTML =
                        '<h2>虎是和獅並列體型最大的兩種貓科動物之一。野外個體可長達3.38公尺、重388.7公斤，' +
                        '是掠食性的肉食動物，有敏銳的聽力、夜視力，可以自由伸縮尖爪和粗壯的犬齒。' +
                        '除了龐大的體型與有力的肌肉之外，最明顯的特徵就是在白色到橘黃色的毛皮上有黑色垂直的條紋，這有助於其在捕獵時隱蔽自身。</h2> ';
                    break;
                case 3:
                    document.getElementById("title").innerHTML =
                        '<h1>Welcome to the Deer story!</h1>';
                    document.getElementById("key").innerHTML =
                        '<img src="img/deer_story.png" height="200px" width="200px">';
                    document.getElementById("Text").innerHTML =
                        '<h2>鹿是偶蹄目反芻亞目中的一類區別於牛、羊等的動物。' +
                        '動物學專著《中國鹿類動物》把鹿類動物定義為「反芻亞目的鹿上科，包括麝科和鹿科動物」，定義到總科。' +
                        '漢語的基本範疇中，鹿的外延則較廣，鼷鹿和長頸鹿等也被包括在內，相當於反芻亞目內牛科和叉角羚科之外的所有動物的統稱。</h2> ';
                    break;
            }
            break;

        case 3:
            switch (i) {
                case 1:
                    document.getElementById("title").innerHTML =
                        '<h1>Welcome to the Owl story!</h1>';
                    document.getElementById("key").innerHTML =
                        '<img src="img/owl_story.png" height="200px" width="200px">';
                    document.getElementById("Text").innerHTML =
                        '<h2>ㄒㄧㄠ、梟、貓頭鷹，是鴞形目（學名：Strigiformes）的鳥類。' +
                        '是掠食性的肉食動物，有敏銳的聽力、夜視力，可以自由伸縮尖爪和粗壯的犬齒。' +
                        '貓頭鷹在西方的愛琴海和基督教文化中是「幸運、智慧」的象徵，而在中國文化中卻有「厄運、恐怖」的意義。</h2> ';
                    break;
                case 2:

                    document.getElementById("title").innerHTML =
                        '<h1>Welcome to the Hummingbird story!</h1>';
                    document.getElementById("key").innerHTML =
                        '<img  src="img/humming_story.png" height="200px" width="200px">';
                    document.getElementById("Text").innerHTML =
                        '<h2>蜂鳥科是"雨燕目"一科，' +
                        '其下物種通稱為蜂鳥，體型小，能夠以快速拍打翅膀（每秒70次，取決於鳥的大小）的方式而懸停在空中，也是唯一可以向後飛的鳥。' +
                        '蜂鳥的飛行本領高超，也被人們稱為「神鳥」、「彗星」、「森林女神」和「花冠」等。</h2> ';
                    break;
                case 3:
                    document.getElementById("title").innerHTML =
                        '<h1>Welcome to the Eagle story!</h1>';
                    document.getElementById("key").innerHTML =
                        '<img  src="img/eagle_story.png" height="200px" width="200px">';
                    document.getElementById("Text").innerHTML =
                        '<h2>鷹在鳥類的分類上指鷹屬的猛禽，也是小型鷹科猛禽的泛稱。' +
                        '鷹為肉食性，嘴彎曲銳利，方便撕開及進食肉塊，腳爪具有鉤爪，性情兇猛，白天活動。' +
                        '年幼的鷹會被親鳥餵養至足以離開巢中，年輕的鷹會在約6周大的時候離巢，以本能來捕獵。</h2> ';
                    break;
            }
            break;
    }
}