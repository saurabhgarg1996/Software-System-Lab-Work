/*
 * Copyright (c) 2006-2009 Erin Catto http://www.box2d.org
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

/* 
 * Base code for CS 251 Software Systems Lab 
 * Department of Computer Science and Engineering, IIT Bombay
 * 
 */


#include "cs251_base.hpp"
#include "render.hpp"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include "GL/freeglut.h"
#endif

#include <cstring>
using namespace std;

#include "dominos.hpp"

namespace cs251
{
  /**  The is the constructor 
   * This is the documentation block for the constructor.
   */ 

  dominos_t::dominos_t()
  {
    //Ground
    b2Body* b1;   /*! 
	           * \brief Used as a pointer to a variable of type b2Body 
	           */ 
    {
      
      b2EdgeShape shape; 								//!  Declares an edge shape variable 
      shape.Set(b2Vec2(-90.0f, 0.0f), b2Vec2(90.0f, 0.0f));		//!  Sets the shape to a rectangular box
      b2BodyDef bd; 								//! Defines a body definition 
      b1 = m_world->CreateBody(&bd); 				//!  Creates the body in the real world with the body definition
      b1->CreateFixture(&shape, 0.0f);				//! Attaches the shape and density to the body 
    }
          
    //Top horizontal shelf
    {
      b2PolygonShape shape;							//! Defines a polygon shape object for the horizontal shelf
      shape.SetAsBox(6.0f, 0.25f);					//!  Sets the shape as a rectangular box
      b2BodyDef bd;									//! Defines a body definition 
      bd.position.Set(-31.0f, 30.0f);				//! Sets the position of the body
      b2Body* ground = m_world->CreateBody(&bd);	//! Creates the body in the real world with the body definition
      ground->CreateFixture(&shape, 0.0f);		//!  Attaches the fixure to the body
    }

    //Dominos
    {
      b2PolygonShape shape;					//! Defines a new polygon shape object for the domino
      shape.SetAsBox(0.1f, 1.0f);			//! Sets the shape of the object a rectangular box
	
      b2FixtureDef fd;						//!  A new fixture variable defined
      fd.shape = &shape;					
      fd.density = 20.0f;					
      fd.friction = 0.1f;					//!  Sets the shape, density and friction of the fixture 		
      for (int i = 0; i < 10; ++i)						
	{
	  b2BodyDef bd;										//! Defines a new body defintion 
	  bd.type = b2_dynamicBody;							//!  Sets the type of the object  as dynamic
	  bd.position.Set(-35.5f + 1.0f * i, 31.25f);		//! Sets the position of the object 
	  b2Body* body = m_world->CreateBody(&bd);			//!  Creates the body in the real world with the given body definition
	  body->CreateFixture(&fd);				//!  Attaches fixtures to the body
	}
    }

    b2Body* b4;								//!  Pointer to a variable of type b2Body
    {
      b2PolygonShape shape;					//!  Defines a new polygon shape body
      shape.SetAsBox(0.25f, 0.25f);			//!  Sets the shpae of the body as a rectangular box
	  
      b2BodyDef bd;							//!  Defines a new body definition
      bd.type = b2_dynamicBody;				//!  Sets the type of the body to be dynamic
      bd.position.Set(-40.0f, 33.0f);		//!  Sets the position of the body
      b4 = m_world->CreateBody(&bd);		//!  Creates the body in the real world
      b4->CreateFixture(&shape, 2.0f);		//!  Attaches the fixtures to the body
    }
	
      


    //The pendulum that knocks the dominos off
    {
      b2Body* b2;							//! Defines a new body for the pendulum bob
      {
	b2PolygonShape shape;					//!  Defines a polygon shape object
	shape.SetAsBox(0.25f, 1.5f);			//!  Sets the shape of the object to a rectangular box
	  
	b2BodyDef bd;							//!  Defines a new body definition
	bd.position.Set(-36.5f, 28.0f);			//!  Sets the position of the body
	b2 = m_world->CreateBody(&bd);	
	b2->CreateFixture(&shape, 10.0f);		//!  Creates the body in the world with the given shape and density
      }
	
      //Another horizontal shelf
      {
	b2PolygonShape shape;					//! Declare a polygon shape object for the horizontal shelf
	shape.SetAsBox(7.0f, 0.25f, b2Vec2(-20.f,20.f), 0.0f);	//!  Sets the shape of the object as a rectangle
	
	b2BodyDef bd;								//! Defines a new body definition  
	bd.position.Set(1.0f, 6.0f);				//!  Sets the position of the body 
	b2Body* ground = m_world->CreateBody(&bd);	//!  Creates the body in the real world with the given body definition
	ground->CreateFixture(&shape, 0.0f);		//!  Attaches fixttures to the body
      }

      b2RevoluteJointDef jd;					//! Declares a revolute joint 
      b2Vec2 anchor;							//! Delares anchor point vector 
      anchor.Set(-37.0f, 40.0f);				//!  Sets the position of the Anchor
      jd.Initialize(b2, b4, anchor);			//!  Initializes the joint with the anchor point
      m_world->CreateJoint(&jd);				//! Creates joint in the world 
    }
      
      
    //! The train of small spheres
    {
      b2Body* spherebody;	//!< Used as a pointer to a variable of type b2Body 
	
      b2CircleShape circle;  //!< Used to define a circular shape for the object to be created 
      circle.m_radius = 0.5; //!< Defines radius for the ciruclar object 
	
      b2FixtureDef ballfd;    //!< Defines a b2FixtureDef object 
      ballfd.shape = &circle; //!< Assign shape, denisty and friction and restitution to the fixture 
      ballfd.density = 1.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;
	
      for (int i = 0; i < 10; ++i)
	{
	  b2BodyDef ballbd;               //! Defines a new box2d Body
	  ballbd.type = b2_dynamicBody;    //! Sets the type of the body as dynamic body
	  ballbd.position.Set(-22.2f + i*1.0, 26.6f);   // Set the position of the centre of the body//
	  spherebody = m_world->CreateBody(&ballbd);     // Creates the body in the world defined//
	  spherebody->CreateFixture(&ballfd);
	}
    }

    //The pulley system
    {
      b2BodyDef *bd = new b2BodyDef;    //! A new body defined 
      bd->type = b2_dynamicBody;        //! Sets the type of the body as dynamic body 
      bd->position.Set(-10,15);         //! Set the position of the body
      bd->fixedRotation = true;         //! Sets that the rotation of the body is fixed 
      
      //The open box
      b2FixtureDef *fd1 = new b2FixtureDef;     //! A new box2d pointer to set fixtures
      fd1->density = 10.0;                      //! Set the density, friction and restitution of the fixture 
      fd1->friction = 0.5;
      fd1->restitution = 0.f;
      fd1->shape = new b2PolygonShape;        //! Define a new polygon shape for making the box 
      b2PolygonShape bs1;         
      bs1.SetAsBox(2,0.2, b2Vec2(0.f,-1.9f), 0);
      fd1->shape = &bs1;                      //! Set the shape of the fixture 
      b2FixtureDef *fd2 = new b2FixtureDef;   //! New fixture variable defined 
      fd2->density = 10.0;                    //! Set the density, friction and restitution of the fixture                   
      fd2->friction = 0.5;  
      fd2->restitution = 0.f;
      fd2->shape = new b2PolygonShape;        //! Set the shape of a fixture as a polygon shape 
      b2PolygonShape bs2;
      bs2.SetAsBox(0.2,2, b2Vec2(2.0f,0.f), 0);   //! Set a polygonshape as a box
      fd2->shape = &bs2;
      b2FixtureDef *fd3 = new b2FixtureDef; 
      fd3->density = 10.0;
      fd3->friction = 0.5;
      fd3->restitution = 0.f;
      fd3->shape = new b2PolygonShape;
      b2PolygonShape bs3;
      bs3.SetAsBox(0.2,2, b2Vec2(-2.0f,0.f), 0);
      fd3->shape = &bs3;
       
      b2Body* box1 = m_world->CreateBody(bd);     //!Finally creating the body defined with the fixtures and properites described above in the real world 
      box1->CreateFixture(fd1);                   //! Attaches fixture to a body
      box1->CreateFixture(fd2);
      box1->CreateFixture(fd3);

      //The bar
      bd->position.Set(10,15);	                 //! Sets the position of the centre of the body
      fd1->density = 34.0;	  
      b2Body* box2 = m_world->CreateBody(bd);
      box2->CreateFixture(fd1);   

      // The pulley joint
      b2PulleyJointDef* myjoint = new b2PulleyJointDef();     //!< Defines a new pulley joint//
      b2Vec2 worldAnchorOnBody1(-10, 15); // Anchor point on body 1 in world axis    //! Defines a new anchor point on the first body to which the pulley is connected
      b2Vec2 worldAnchorOnBody2(10, 15); // Anchor point on body 2 in world axis    //! Defines a new anchor point on the first body to which the pulley is connected
      b2Vec2 worldAnchorGround1(-10, 20); // Anchor point for ground 1 in world axis //! Defines a new anchor point on the ground through which the string is connected to body 1
      b2Vec2 worldAnchorGround2(10, 20); // Anchor point for ground 2 in world axis  //! Defines a new anchor point on the ground through which the string is connected to body 2
      float32 ratio = 1.0f; // Define ratio             //! Set the ratio constraint for ropes to move 
      myjoint->Initialize(box1, box2, worldAnchorGround1, worldAnchorGround2, box1->GetWorldCenter(), box2->GetWorldCenter(), ratio);
      m_world->CreateJoint(myjoint);        //! Finally creates the joint in the world frame 
    }

    //The revolving horizontal platform
    {
      b2PolygonShape shape;                 //! Make a new polygonshape object 
      shape.SetAsBox(2.2f, 0.2f);           //! Set the shape of the body as a box with given centres 
	
      b2BodyDef bd;
      bd.position.Set(14.0f, 14.0f);
      bd.type = b2_dynamicBody;             //! Make a new body and set its position 
      b2Body* body = m_world->CreateBody(&bd);    //! Creates the body in the world 
      b2FixtureDef *fd = new b2FixtureDef;      
      fd->density = 1.f;                    //! Set the features of the fixture
      fd->shape = new b2PolygonShape;       //! Set the shape of the fixture 
      fd->shape = &shape;
      body->CreateFixture(fd);              //! Add fixtures to the body 

      b2PolygonShape shape2;                //! new polygonshape made 
      shape2.SetAsBox(0.2f, 2.0f);          //! Set the shape of the object as a box 
      b2BodyDef bd2;
      bd2.position.Set(14.0f, 16.0f);       //! Set the position of the new body defined 
      b2Body* body2 = m_world->CreateBody(&bd2);    //! Create a body int the world

      b2RevoluteJointDef jointDef;            //! Define a revolute joint between 2 bodies 
      jointDef.bodyA = body;                  //! Define the bodies which will have a joint between them  here bodyA 
      jointDef.bodyB = body2;                 //! Define the bodies which will have a joint between them  here bodyB 
      jointDef.localAnchorA.Set(0,0);         //! Set the local anchor point on the first body (bodyA)
      jointDef.localAnchorB.Set(0,0);         //! Set the local anchor point on the second body (bodyB)
      jointDef.collideConnected = false;      //! By setting this variable as true, make sure that the bodies are connected even during collisions
      m_world->CreateJoint(&jointDef);        //! Creates joint in the world 
    }

    //The heavy sphere on the platform
    {
      b2Body* sbody;				//! Defines a new body to represent sphere on the platform
      b2CircleShape circle;			//! Add a circular shape to the circle 
      circle.m_radius = 1.0;			//! Set the radius of a circle 
	
      b2FixtureDef ballfd;			//! Defines a new fixture 
      ballfd.shape = &circle;
      ballfd.density = 50.0f;
      ballfd.friction = 0.0f;			//! Set shape, density and friction to the fixture 
      ballfd.restitution = 0.0f;
      b2BodyDef ballbd;				//! Define a new body in box2d
      ballbd.type = b2_dynamicBody;		//! Set the type of the body as dynamic 
      ballbd.position.Set(14.0f, 18.0f);	//! Set the position as the centre of  the body 
      sbody = m_world->CreateBody(&ballbd);	
      sbody->CreateFixture(&ballfd);		//! Create body in the world and add the fixtures
    }


    //The see-saw system at the bottom
    {
      //The triangle wedge
      b2Body* sbody;					//!  Define a pointer to a varible of type b2Body
      b2PolygonShape poly;				//!  Defines a new polygon shape body
      b2Vec2 vertices[3];				//!  Creates 3 vectors 
      vertices[0].Set(-1,0);			//!  Sets the 3 vectors' positions
      vertices[1].Set(1,0);
      vertices[2].Set(0,1.5);			
      poly.Set(vertices, 3);			//!  Sets the vertices of the polygon shape
      b2FixtureDef wedgefd;				//! Defines a new fixture and set its shape, density, friction, restitution 
      wedgefd.shape = &poly;			
      wedgefd.density = 10.0f;			
      wedgefd.friction = 0.0f;
      wedgefd.restitution = 0.0f;
      b2BodyDef wedgebd;				//! Defines a new body 
      wedgebd.position.Set(30.0f, 0.0f);	//! Sets the position of the body 
      sbody = m_world->CreateBody(&wedgebd);	//! Creates the bosy in the real world with trhe given definition 
      sbody->CreateFixture(&wedgefd);			//! Attaches the fixtures to the body 

      //The plank on top of the wedge
      b2PolygonShape shape;				//!  Defines a new polygon shape body
      shape.SetAsBox(15.0f, 0.2f);		//!  Sets the shape as a rectangular box
      b2BodyDef bd2;					//!  Defines a new body definition
      bd2.position.Set(30.0f, 1.5f);	//!  Sets the position of the body
      //bd2.type = b2_dynamicBody;			//!  Sets the type of the body as dynamic
      b2Body* body = m_world->CreateBody(&bd2);				//!  Creates the body in the real world with the given body definition
      b2FixtureDef *fd2 = new b2FixtureDef;				//!  Defines a new fixture definition
      fd2->density = 1.0f;								//!  Sets the density and shape of the fixture
      fd2->shape = new b2PolygonShape;
      fd2->shape = &shape;
      body->CreateFixture(fd2);						//!  Attaches the fixture to the body

      b2RevoluteJointDef jd;						//!  Defines a Revolute joint definition
      b2Vec2 anchor;								//!  Defines a vector as an anchor for the joint
      anchor.Set(30.0f, 1.5f);						//!  Sets the position of the anchor
      jd.Initialize(sbody, body, anchor);				//!  Initializes the joint with the bodies and the anchor
      m_world->CreateJoint(&jd);					//!  Creates the joint in the real world

      //The light box on the right side of the see-saw
      b2PolygonShape shape2;					//!  Defines a new polygon shape object
      shape2.SetAsBox(2.0f, 2.0f);				//!  Sets the shape of the object as a rectangular box
      b2BodyDef bd3;							//!  Defines a  new body deifinition
      bd3.position.Set(40.0f, 2.0f);			//!  Sets the position of the body 
      bd3.type = b2_dynamicBody;				//!  Sets the type of the body as dynamic
      b2Body* body3 = m_world->CreateBody(&bd3);	//!  Creates the body in the real world
      b2FixtureDef *fd3 = new b2FixtureDef;		//!  Defines a new fixture definition
      fd3->density = 0.01f;						//!  Sets the density and shape of the fixture
      fd3->shape = new b2PolygonShape;
      fd3->shape = &shape2;
      body3->CreateFixture(fd3);				//!  Attaches the fixture to the body
    }

	//! Making a Balloon--------------- First new element --------------
    {
      b2Body* sbody;                                                   
      b2CircleShape circle;                                                              
      b2FixtureDef ballfd; 
      b2BodyDef ballbd;
      circle.m_radius = 1.5f;                                
      ballfd.shape = &circle; 				//! Define the shape of the balloon                             
      ballfd.friction = 0.0f;      
      ballfd.density = 5.0f;                                                    
      ballfd.restitution = 0.0f;                        //! Set the dynamic nature of the balloon                                
      ballbd.type = b2_dynamicBody;                     
      ballbd.position.Set(10.0f, 12.0f);
      sbody = m_world->CreateBody(&ballbd);              
      sbody -> SetGravityScale(-0.1f);                      //! Setting Negative Gravity so that balloon can rise up.
      sbody->CreateFixture(&ballfd);                     
    }

  //!Balls ----------------------------- Second new element----------------------
      {
      b2Body* spherebody;
  
     b2CircleShape circle;
     circle.m_radius = 0.2;
  
     b2FixtureDef ballfd;			//! Defines a ball fixture 
     ballfd.shape = &circle;		 	//! Giving it a shape of a circle
      ballfd.density = 1.0f;
     ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;		//! Adding properties to the fixture
  for(int j=0;j<5;j++){
     for (int i = 0; i < 10; ++i)
  {
    b2BodyDef ballbd;
    ballbd.type = b2_dynamicBody;
    ballbd.position.Set(-20.2f + i*0.2, 20.6f+j*0.19);
    spherebody = m_world->CreateBody(&ballbd);
    spherebody->CreateFixture(&ballfd);			//! Create this body in the world
  }
  }
  }

  //!Spring mass system - A spring mass system which can act as 2 bodies connected to a spring
  //! ------------ Third element ------------------
    {
      b2CircleShape circle;
      circle.m_radius = 1.0;
      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 15.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;
      b2BodyDef ballbd;
      ballbd.type = b2_dynamicBody;
      ballbd.position.Set(-6.5f, 34.25f);
      b2Body* body = m_world->CreateBody(&ballbd);
      body->CreateFixture(&ballfd);

      b2CircleShape circle1;			//! Define shapes of the ball connected to the spring
      circle1.m_radius = 1.0;
      b2FixtureDef ballfd1;
      ballfd1.shape = &circle1;
      ballfd1.density = 15.0f;
      ballfd1.friction = 0.0f;
      ballfd1.restitution = 0.0f;		//! Set the fixtures of the body
      b2BodyDef ballbd1;
      ballbd1.type = b2_dynamicBody;     
      ballbd1.position.Set(-12.5f, 34.25f);
      b2Body* body2 = m_world->CreateBody(&ballbd1);    
      body2->CreateFixture(&ballfd1); 

      // b2DistanceJointDef distance_joint;
      // //const b2Vec2 AnchorA, AnchorB;
      //AnchorA.Set(0.0, 0.0);
      //AnchorB.Set(0.0, 0.0);
      // distance_joint.Initialize(body, body2,b2Vec2(0,0),b2Vec2(0,0));
      // distance_joint.length = 0.01f;
      // distance_joint.collideConnected = true;
      // distance_joint.frequencyHz = 2.0f;
      // distance_joint.dampingRatio = 0.2f;
      // m_world->CreateJoint(&distance_joint);
      b2PrismaticJointDef jointDef;			//! Define a prismatic joint between the bodies

    b2Vec2 worldAxis(2.5f, 0.0f);

    jointDef.Initialize(body, body2, body->GetWorldCenter(), worldAxis);

    jointDef.lowerTranslation = -1.5f;			//! Initializing the joint between the bodies

    jointDef.upperTranslation = 1.5f;

    jointDef.enableLimit = true;

    jointDef.maxMotorForce =  0.0f;			

    jointDef.motorSpeed = 0.0f;

    jointDef.enableMotor = true;
    m_world->CreateJoint(&jointDef);

    }      

      
  }

  sim_t *sim = new sim_t("Dominos", dominos_t::create);
}
