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
      
This is the ray which shoots from player's position and hit the wall which is either (further away from)/ (nearer to) the player. Since we have the coordinates of this ray now
Let's get the distance between the ray at which the wall hit and the player's position.

![1](https://user-images.githubusercontent.com/81755254/196061701-d6f2a160-6471-46ed-8c70-9fdb6b370f1c.jpg)

  