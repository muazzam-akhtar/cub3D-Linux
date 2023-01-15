# Raycasting Algorithm

My Approach for the algorithm are the references which I gathered from the guideline of [cub3D](https://lodev.org/cgtutor/raycasting.html) and from the videos of raycasting. 

Angles defined in the algorithm are mostly in degrees, some are mentioned in radians. Why? The math functions in C languages works in Radians.

      Note: Degree To Radian: angle x (PI / 180)
            Radian To Degree: angle x (180 / PI)

Thanks to [Hussain Awadh](https://github.com/MisterTooh) for collaborating with me on this fun project. Hope to work with you again in future projects.
Topics covered in this project are:
* [Basic Raycasting](https://github.com/Genius-gambit/cub3D-Linux/edit/master/Raycasting%20Algorithm/ReadMe.md#basic-raycasting).
* [Rotation of the player](https://github.com/Genius-gambit/cub3D-Linux/edit/master/Raycasting%20Algorithm/ReadMe.md#rotation-of-the-player).
* [Movements of the Player](https://github.com/Genius-gambit/cub3D-Linux/edit/master/Raycasting%20Algorithm/ReadMe.md#movements).
* [Wall Collision](https://github.com/Genius-gambit/cub3D-Linux/edit/master/Raycasting%20Algorithm/ReadMe.md#wall-collision).
* [Edge Cases](https://github.com/Genius-gambit/cub3D-Linux/edit/master/Raycasting%20Algorithm/ReadMe.md#edge-cases).
* [3D Perspective](https://github.com/Genius-gambit/cub3D-Linux/edit/master/Raycasting%20Algorithm/ReadMe.md#3d-perspective)
* [Ray](https://github.com/Genius-gambit/cub3D-Linux/edit/master/Raycasting%20Algorithm/ReadMe.md#ray)
* [Right Angle Triangle](https://github.com/Genius-gambit/cub3D-Linux/edit/master/Raycasting%20Algorithm/ReadMe.md#right-angle-triangle)
* [Cube](https://github.com/Genius-gambit/cub3D-Linux/edit/master/Raycasting%20Algorithm/ReadMe.md#cube)
* [Wall Height](https://github.com/Genius-gambit/cub3D-Linux/edit/master/Raycasting%20Algorithm/ReadMe.md#wall-height)
* [DDA Algorithm]

![begin](https://user-images.githubusercontent.com/81755254/195951594-38adbeff-ec0a-4c3b-9cce-2159907b9a0f.gif)

# Basic Raycasting

Let's talk about the field of view for the player. 
For my raycasting I took the field of view as 70 degree which will be 35 degrees from the left and the 35 degrees to the right.

Based on the project cub3D:
* If the player is facing North: Angle of the player will be 270 degree.
* If the player is facing South: Angle of the player will be 90 degree.
* If the player is facing East: Angle of the player will be 180 degree.
* If the player is facing West: Angle of the player will be 0 degree.

## Rotation of the player

Given the angle of the player, in order to rotate the player towards the left, we can subtract with any constant degree.
In my case, I deduct the angle of the player with 0.1(since we're working with radian, so in degree the constant will be 5.73 degrees)
On the other hand if we rotate towards right, we can add the angle with constant 0.1 (the same thing).

Observing the figure of polar coordinates, we can slice the angles in four quadrants.

* First quadrant: 0 <= angle < 90
* Second quadrant: 90 <= angle < 180
* Third quadrant: 180 <= angle < 270
* Fourth quadrant: 270 <= angle < 360

![quadrants](https://user-images.githubusercontent.com/81755254/195952993-769a7544-bb9c-446d-bffc-cf5db67e8199.png)

In case, if angle is less than 0, this indicates that the angle lies in the fourth quadrant, so we can add the resulted angle with 360. Vice versa, if the angle is greater than 360, this indicates that the angle lies in the first quadrant, so we can deduct the resulted angle with 360.
![rot_right](https://user-images.githubusercontent.com/81755254/195990993-2953b0fc-03d2-4e74-9be7-b268f00640b7.gif)                 ![rot_left](https://user-images.githubusercontent.com/81755254/195990961-4604b47e-a510-4ed2-8c4e-5a2addd344f5.gif)

## Movements:
In case of movements, we can calculate the change in value of x coordinate and y coordinate. Since we have the angle of the player.
###### Forward Movement:
   * To check the change in x-coordinate: cos(angle of the player) * distance.
   * To check the change in y-coordinate: sin(angle of the player) * distance. Why?

> In account if we implement Euler's theorem which states that how we can convert cartesian coordinates(x, y) to polar coordinates(r, angle). Then with any point in (x, y). If we plan to move one or any amount of grids away at any angle. The change will give us the result with the help of polar coordinates.
Then we can update the player's position by adding the position of the player with the change in both the coordinates.
For example if point is at the origin, angle lies in the first quadrant and we're moving one grid away(r = 1).

![polar_curve61](https://user-images.githubusercontent.com/81755254/196059957-8a15bb60-b5ca-4b18-bdaa-d36dd52f367f.png)

And let's say if we're moving half a grid away and taking all the angles.

![polar_curve11](https://user-images.githubusercontent.com/81755254/196059895-2e035193-7a20-49e9-90da-3ea1f5d33d2c.png)


![cartesian-polar-coordinates-conversion-formulas](https://user-images.githubusercontent.com/81755254/195955095-87f89a15-1b1c-4581-9e83-1b04e7d6040a.png)                                                                      ![math_polar](https://user-images.githubusercontent.com/81755254/195955121-6c418c72-a16c-4dfa-a4c1-850eb61c0456.png)

###### Backward Movement:
  * Same as the previous step except this time instead of adding the change in both the coordinates, we deduct it.

###### Right Movement:
  This time we will work with angles:
* To check the change in x-coordinate: cos(angle of the player + 90 degrees) * distance.
* To check the change in y-coordinate: sin(angle of the player + 90 degrees) * distance.
Update the player's position by adding the position of the player with the change in both the coordinates.

###### Left Movement:
  * Same as the Right Movement except instead of adding the change in both the coordinates, we deduct it.

        Note: It's upto you how much distance you want for your player to cover.

## Wall Collision:
  To fix wall collision, what I did was I placed four arcs around my player which can detect a wall. Just like the rays but this time we will have the specific distance away from the player's position, For example: Forward wall collision will carry an arc. For that arc, we will calculate 7 coordinates. Initial angle will be the angle of the player - 35 degrees. Based on the angle we can have coordinates:
  
    w_x(A variable for the x-coordinate of the wall collision detector),
    w_y(A variable for the y-coordinate of the wall collision detector),
    w_angle(Angle of this wall_detector variable)
    constant is for how much distance we want from the player to detect the wall.(Your Choice)
    
    w_x = x_coordinate of the player + cos(w_ang) * constant
    w_y = y_coordinate of the player + sin(w_ang) * constant;
    Initial value of w_ang = angle of the player - 35 degrees.
    
I gave constant as 0.125. Then we can increment the angle of the wall collision by 10 degrees(in radian: 10 * PI / 180) and have this iteration in 7 loops. Have wall collision flag if any of the coordinates hits the wall.
We can do the same for the other directions as well.
* For the right direction, Initial value of angle of the wall collision(initial) = PI / 2 + angle of the player - 35 degrees.
* For the left direction, Initial value of angle of the wall collision(initial) = (3 * PI / 2) + angle of the player - 35 degrees.
* For backward direction, Initial value of angle of the wall collision(initial) = angle of the player - 35 degrees - PI.

It would look like this

![wall_coll](https://user-images.githubusercontent.com/81755254/195994638-c56f147a-b2fc-4248-821b-4fa26f985072.png)

These purple arcs will act as the wall detectors for our player.

![wall_coll](https://user-images.githubusercontent.com/81755254/195994034-553e5022-1572-4bab-ba32-dd18bb083d0c.gif)

## Edge Cases:
This is the last bug which we want to make it perfect for the player not to go through the walls if walls are placed as diagonals. For example

![edge cases](https://user-images.githubusercontent.com/81755254/195993457-09751416-e1b4-4da7-b539-1013debec8a4.gif)


The given figure represents that the wall doesn't exist between edges but practically this is wrong. This is known as the edge cases of raycasting. In order to fix this bug I hard coded this problem.

![Edge cases](https://user-images.githubusercontent.com/81755254/195993497-0ad5e8fb-fd08-4f2d-9a3b-5f5dfeb9735f.png)

After implementing the basics of raycasting, this is what it would look like in 2D perspective.

![posted](https://user-images.githubusercontent.com/81755254/179372759-3deef13a-9706-4695-9ed9-31cfe4b3f0b9.gif)

# 3D Perspective:

## Ray

Lets draw one ray which can hit the wall, take the angle of the ray as player's angle - 35 degrees.
      
      x = x-coordinate of the ray, y = y-coordinate of the ray, cover = distance for the ray to cover in each iteration,
      wall_hit = a hit trigger.

      x = player's_pos_x_co;
      y = player's_pos_y_co;
      while (!wall_hit)
      {
        x += cover * cos(angle of the player);
        y += cover * sin(angle of the player);
        if (map[y][x] == '1'
          wall_hit = 1;
      }
      
      Cover should be better to have small number in order to have accurate results when hitting the wall.

![raycastmiss](https://user-images.githubusercontent.com/81755254/196062368-404c8c02-22ce-4a87-bfda-e326db01c2af.gif)
![raycastmiss2](https://user-images.githubusercontent.com/81755254/196062372-c2942a51-ea9d-4d88-be5d-2000b801b2a1.gif)

## Right Angle Triangle

From the figure below, This is the ray which shoots from player's position and hit the wall which is either (further away from)/ (nearer to) the player. Since we have the coordinates of this ray now

![ray](https://user-images.githubusercontent.com/81755254/196182339-13b024c3-1e33-443d-90ad-66f9aeebd962.png)

Let's get the distance between the ray at which the wall hit and the player's position.

![1](https://user-images.githubusercontent.com/81755254/196061701-d6f2a160-6471-46ed-8c70-9fdb6b370f1c.jpg)

From C to A we have the distance of the wall. But this is not the correct distance from the wall. As from the figure, Ray distance is more than when the player is facing the wall so we can calculate the adjacent side of this triangle using [Pythagoras Theorem](https://www.cuemath.com/geometry/pythagoras-theorem/) and since we have the value for AC, we can calculate the distance of BC.

      Right Angle Triangle Properties:
      
      AC = Hypotenuse, BC = adjacent, AB = Perpendicular
      AC^2 = sqrt(BC^2 + AB^2)
      Sum of all the angles = 180 degrees.
      One of the angles is always 90 degrees
      In this case, Angle B is 90 degrees.
      
      Calculating the Adjacent side:
           BC = AC x cos(angle of the ray), since cos(angle) = Adjacent / Hypotenuse

## Cube

Now we have got the adjacent side we will draw a line which will act as a wall height. Since we're working with cubes. A brief description for the [Cube](https://en.wikipedia.org/wiki/Cube). Cube has all sides equal. So say if we take block size as 8. Then all the sides of this cube is 8.
Now let's draw one wall height with the given ray.
      
      scalar = a value which can make the picture perfect for the window size,
      BLOCK_SIZE = 8, adjacent = adjacent side of the wall for the ray.
      
      wall_height = (BLOCK_SIZE x scalar) / adjacent 

## Wall Height

<img width="100" alt="cube_one1" src="https://user-images.githubusercontent.com/81755254/196187666-619849e9-fd60-488c-bae9-8a68268165d5.png">

The above result is the wall height of one ray. Lets continue the iteration for multiple rays.
For iterations, it would be better if we're moving by 1 in x-coordinate.
      
      For iterations in angles: angle += (FIELD_OF_VIEW / NUMBER OF RAYS)- this operation will result in degrees, convert it in radians.

Repeat the process for rays from [here](https://github.com/Genius-gambit/cub3D-Linux/edit/master/Raycasting%20Algorithm/ReadMe.md#ray) then.

After performing the whole operation, we will get this.

<img width="200" alt="cube" src="https://user-images.githubusercontent.com/81755254/196190055-e4ade114-f29e-4ea7-acd3-d9ba2d1a0678.png">

## DDA Algorithm

Above algorithm/method taskes more time depending on the distance between the player and the wall. For faster FPS or avoiding the lag of the game, I approached DDA Algorithm. 

The approach of this line drawing algorithm is pretty simple. From moving one grid to the other, we only need to check if it's a horizontal or vertical hit.

      Let c_x = change in x, c_y = change in y, angle = angle of the ray, dx = rate of change in x when x moves one unit of grid corresponding to change in y,
      dy = rate of change in y when y moves one unit of grid corresponding to change in x, x_step = steps of each unit of x based on the change in x, y_step = steps of       each unit of y based on the change in y, x_pos = current x-position of the player(in float), y_pos = current y-position of the player(in float),
      m_x = x-coordinates in int value, m_y = y-coordinates in int value, dist_x = distance if x moves one unit, dist_y = distance if y moves one unit.
      c_x = cos(angle), c_y = sin(angle)
      m_x = (int)x_pos
      m_y = (int)y_pos
      d_x = (1 + (c_y / c_x)^2)^1/2
      d_y = (1 + (c_x / c_y)^2)^1/2

First we need to calculate the distance of both scenarios if x moves one unit or y moves one unit and compare which has less distance. If x is hitting first then it's a horizontal hit else it's a vertical hit.

      if (c_x < 0)
            x_step = -1
            dist_x = (x_pos - m_x) * dx;
      else
            x_step = 1
            dist_x = ((int)x_pos + 1.0 - x_pos) * dx;
      if (c_y < 0)
            y_step = -1
            dist_y = (y_pos - m_y) * dy;
      else
            y_step = 1
            dist_y = ((int)y_pos + 1.0 - y_pos) * dy;

Now we have steps, rate of change of both x and y, we can start a while loop for every iteration of the unit of grid. We declare a wall trigger and a side to get the indication if it's a horizontal or vertical hit.

      wall = 0;
      side = 0;
      while (!wall)
      {
            if (dist_x < dist_y)
		{
			dist_x += dx;
			m_x += x_step;
			side = 0;
		}
		else
		{
			dist_y += dy;
			m_y += y_step;
			side = 1;
		}
		if (map[m_y][m_x] == '1')
			wall = 1;
       }

If it's a vertical hit then to get the new value of x, we can use this equation: y2 = m_y, y1 = y-coordinate of the player, x2 = need to find, x1 = x-coordinate of the player, angle = angle of the ray.
      tan(angle) = (y2 - y1) / (x2 -x1)

If it's a horizontal hit vice-versa: y2 = need to find, y1 = y-coordinate of the player, x2 = m_x, x1 = x-coordinate of the player, angle = angle of the ray.
      tan(angle) = (y2 - y1) / (x2 -x1)
