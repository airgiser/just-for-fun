var isMouseDown = false;

function showCoord(e)
{
    x = e.clientX;
    y = e.clientY;
    content = document.getElementById("coord");
    content.innerHTML = "X: " + x + ", " + "Y: " + y;
}

function clearCoord(e)
{
    document.getElementById("coord").innerHTML = "";
}

function mouseDown(e)
{
    isMouseDown = true;
    var canvas=document.getElementById('simpleCanvas');
    var context=canvas.getContext('2d');
    context.moveTo(e.clientX, e.clientY);
}

function mouseMove(e)
{
    showCoord(e);
    if (isMouseDown)
    {
        var canvas=document.getElementById('simpleCanvas');
        var context=canvas.getContext('2d');
    }
}

function mouseUp(e)
{
    isMouseDown = false;
    var canvas=document.getElementById('simpleCanvas');
    var context=canvas.getContext('2d');
    context.lineTo(e.clientX, e.clientY);
    context.stroke();
}

function mouseDoubleClick(e)
{

}

function mouseOut(e)
{
    clearCoord(e);
}

