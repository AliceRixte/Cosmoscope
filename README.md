Cosmoscope
============

The Cosmoscope aims to be a small and simple graphic programming language that aims to draw beautiful geometric shapes. The main idea relies on a concept similar to the spirograph : we compose 2D parametric **functions** by linking the origin of the coordinate system of one function to another function. Doing so, those functions are traced relatively to their origin shift, which is why I called them **relative functions**. 

This concept is a wide generalization of the spirograph : every function traced by the spirograph can be traced by the cosmoscope but the cosmoscope can trace theoretically any computable 2D parametric function, using composition more as a tool rather than a constraint.

Units
--------

Relative functions use the **time** elapsed since the beginning of the program to compute their **cartesian** or **polar coordinates**, as well as their **color** at the time ``t`` in *milliseconds*.

The length are described using a *percentage* of the half of the window's diagonal. The angle use degrees, with 0° being the horizontal and using the trigonometric direction. As a consequence, for any square window, the position of the right top corner is ``(r,th) = (100,45)`` or, in cartesian style ``(x,y) = (sin(45)*100, cos(45)*100)`` , the top left corner is ``(r,th) = (100,135)``, the bottom left corner is ``(r,th) = (100,225) = (100,-135)`` and the bottom right corner is ``(r,th) = (100,315) = (100,-45)``.

As a consequence, ``x``, ``y`` and ``r`` all evolve between ``-100`` and ``+100``. Even in that range, a lot of points are actually outside of the window and won't be drawn, but this allows to make the Cosmoscope programs independent from the window in which they will be executed.

Syntax 
---------------

For now, the syntax of the Cosmoscope language relies deeply on JSON.

Each relative function is identified by a unique number called ``id`` and its origin is either linked to another function, called the **parent function** or to the origin of the program's window, which ``id`` is bound to ``-1``. 

Here is an example of a Cosmoscope program combining two circles of radius 50% of the window : 

````JSON
{
  "func_list" : [
    {
      "id"     : 0    ,
      "parent" : -1   ,
      "r"      : "50" ,
      "th"     : "t" 
    },
    {
      "id"     : 1    ,
      "parent" : 0    ,
      "r"      : "50" ,
      "th"     : "t"
    }
  ]
}      
````

In this example, the circles will be drawn with the last color that was used by the language. It corresponds to the center of the window of the drawing. The ``x`` axis goes from the center to the right of the window and the ``y`` axis from the center to the top of the window. Each time you want to specify a coordinate, you can either do so in cartesian coordinates using ``"x"`` and  ``"y"`` or in polar coordinates using ``"r"`` and ``"th"`` where ``th`` means ``theta``.

The origin and colors can be modified as it is showed in the next example. Colors use an ``rgba`` format, with **red**, **green**, **blue**  and **alpha** ranging from ``0`` to ``1``.


````JSON
{
  "func_list" : [
    {
      "id" : 0,
      "parent" : -1,
      "intervals" : [
        {
          "begin" : 0 , 
          "end" : 10,
          "start" : {
            "x" : 50,
            "y" : -25
          },
          "finish" : {
            "r" : 20,
            "th" : 315
          }
        },
        {
          "begin" : 10 , 
          "end" : 20  ,
          "loop" : 5  ,
          "tt" : "sqrt(t)",
          "x" : "sin(t)",
          "y" : "t*t",
          "color" : [0,0,"x + t",1] 
        }
      ]
    }
  ]
}
      
````

sup : -1 infinity, -2
