k = 2;

class Node {
    constructor(point, axis) {
        this.point = point;
        this.left = null;
        this.right = null;
        this.axis = axis;
    }
}

// function getHeight(node) { }
// function generate_dot(node) { }



function build_kdtree(points, depth = 0) {
    var n = points.length;
    var axis = depth % k; if (n <= 0) {
        return null;
    }
    if (n == 1) {
        return new Node(points[0], axis)
    } var median = Math.floor(points.length / 2);    // sort by the axis
    points.sort(function (a, b) {
        return a[axis] - b[axis];
    });
    // console.log(points);
    var left = points.slice(0, median);
    var right = points.slice(median + 1);
    // console.log(right);   ///coment +
    var node = new Node(points[median].slice(0, k), axis);
    node.left = build_kdtree(left, depth + 1);
    node.right = build_kdtree(right, depth + 1);
    return node;
}



////EX ESKEC

function distanceSquared(point1, point2) {
    var distance = 0;
    for (var i = 0; i < k; i++)
        distance += Math.pow((point1[i] - point2[i]), 2);
    return Math.sqrt(distance);
}

// function closest_point_brute_force(points, point) { }
// function naive_closest_point(node, point, depth = 0, best = null) { }




// PARTE DE DATA


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
var point = [140, 90]; //query





//

function getHeight(node) {
    if (node === null) {
        return 0;
    }    // find the height of each subtree
    var lh = getHeight(node.left);
    var rh = getHeight(node.right); 
    return 1 + Math.max(lh, rh);
}

function generate_dot(node) {
    // alert("prueba");
    if (node === null) {
        return "";
    }
    var tmp = ''; 
    if (node.left != null) {
        tmp += '"' + node.point.toString() + '"' + ' -> ' + '"' + node.left.point.toString() + '"' + ';\n';
        tmp += generate_dot(node.left);
    }
    if (node.right != null) {
        tmp += '"' + node.point.toString() + '"' + ' -> ' + '"' + node.right.point.toString() + '"' + ';\n';
        tmp += generate_dot(node.right);
    } 
    
    return tmp;
}







/// Segunda extraccion En clase

function closest_point_brute_force(points, point) {
    var distance = null;
    var best_distance = null;
    var best_point = null;
    for (let i = 0; i < points.length; i++) {
        distance = distanceSquared(points[i], point);
        // console.log(distance);
        if (best_distance === null || distance < best_distance) {
            best_distance = distance;
            //best_point = { 'point': points[i], 'distance': distance }
            best_point = points[i];
        }
    } return best_point;
}



function naive_closest_point(node, point, depth = 0, best = null) {
    //algorithm
    //1. best =8 min(distance(point, node.point), best)
    //2. chose the branch according to axis per level
    //3. recursevely call by branch chosed    
    if (node === null)
        return best; 
    var axis = depth % k;

    // if (point[axis] < node.point[axis])
    // console.log("axis",point[axis])
    // console.log("node axis",node.point[axis][1])


    var next_best = null; //next best point
    var next_branch = null; //next node brach to look for    
    if (best === null || (distanceSquared(best, point) > distanceSquared(node.point, point)))
        next_best = node.point;
    else
        next_best = best;
    // if (point[axis] < node.point[axis])
    if (point[axis] < node.point[axis])
        next_branch = node.left
    else
        next_branch = node.right
    return naive_closest_point(next_branch, point, depth + 1, next_best);
}



//Consultas 
var point = [140, 90]; //punto que pensamos buscar

function dibujar_busqueda(data){
    for (let i = 0; i < data.length; i++) {
        fill(255, 0, 0);
        // circle(x, height - y, 7); //200-y para q se dibuje apropiadamente
        circle(data[i][0], height - data[i][1], 7); //200-y para q se dibuje apropiadamente
        textSize(8);
        text(data[i][0] + ',' + data[i][1], data[i][0] + 5, height - data[i][1]);//200-y para q se dibuje apropiadamente   
    }
}



// dibujar_busqueda(data);


// dibujar_busqueda(point);
console.log("Punto a Tomar en consideracion: " , point);
console.log("Obtener Altura del KDTree: ", getHeight(build_kdtree(data)));
console.log("Punto mas cercano por fuerza bruta: ", closest_point_brute_force(data, point));
// console.log("ss: ", naive_closest_point(data, point));
console.log("Punto mas cercano por Naive Closest Point: ");
console.log("Generacion de Dot: ",'\n', 'digraph G { \n',generate_dot(build_kdtree(data)),'}\n');
//  
