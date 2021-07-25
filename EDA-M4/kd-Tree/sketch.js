
function setup() {
    var width = 250;
    var height = 300;
    createCanvas(width, height);
    background(255);
    for (var x = 0; x < width; x += width / 10) {


        for (var y = 0; y < height; y += height / 5) {
            stroke(0, 0, 0);
            strokeWeight(1);
            line(x, 0, x, height);
            line(0, y, width, y);
        }
    }


    // var data = [];
    // data = puntos_gen();
    
 var data = [
    [40, 70],
    [70, 130],
    [90, 40],
    [110, 100],
    [140, 110],
    [160, 100],
    [150, 30],
    [10, 10]
    
 ];

    // console.log("puntos gen",data);
    // console.log("puntos gen",data[0,[0]]);

    for (let i = 0; i < data.length; i++) {
        fill(0, 0, 0);
        // circle(x, height - y, 7); //200-y para q se dibuje apropiadamente
        circle(data[i][0], height - data[i][1], 7); //200-y para q se dibuje apropiadamente
        textSize(8);
        text(data[i][0] + ',' + data[i][1], data[i][0] + 5, height - data[i][1]);//200-y para q se dibuje apropiadamente   
    }
    var root = build_kdtree(data);
    // var root = build_kdtree(puntos_gen);
    // console.log(root);
}
 

function puntos_gen() {
    var temp_data = []
    for (let i = 0; i < 12; i++) {
        var x = Math.floor(Math.random() * 250);
        var y = Math.floor(Math.random() * 300);
        temp_data.push([x, y]);
       
    }
    return temp_data;
}


////////////////para probar los array 
// var tet= []
// tet = puntos_gen()
// console.log("Lista: ",tet)
// console.log("Accedienndo 0 0 ",tet[0][0]);
// console.log("Accedienndo 0 1 ",tet[0][1]);




// k = 2;
// class Node {
//     constructor(point, axis) {
//         this.point = point;
//         this.left = null;
//         this.right = null;
//         this.axis = axis;
//     }
// }





//END



// setup()

