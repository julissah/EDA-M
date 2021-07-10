 let qt;
 function setup()
{
    createCanvas(800, 800);
   
    let boundary= new Rectangle(400, 400, 400, 400);
    qt = new QuadTree(boundary, 4);

    /*for(i=0; i<Math.floor(Math.random() * 100000) ; i++)
    {
        let p =new Point(random(width), random(height));
        qt.insert(p);
    }
*/background(0);
    
}

function draw()
{
    if(mouseIsPressed)
    {
        let pt=new Point(mouseX, mouseY);
        qt.insert(pt);
    }

    qt.show();
}



    
