### GLUT implements event-driven programming model for our window. For example, when the user clicks or moves the mouse,
GLUT can call our event handler function and allow our program to keep up with the user's actions. 

  
    glutReshapeFunc( change_viewport );      // when window is resized
    glutDisplayFunc( render );               // when window needs to be drawn
    glutIdleFunc( animate );                 // when there is nothing else to do
    glutMouseFunc( callback_mouse_button );  // when mouse is clicked
    glutKeyboardFunc( keyboard_down );       // when a key is down
    glutKeyboardUpFunc( keyboard_up );       // when the key goes up
    glutPassiveMotionFunc( look );           // when mouse moves
    glutMotionFunc( look );                  // when mouse drags around
