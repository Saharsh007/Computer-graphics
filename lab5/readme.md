##http://www.c-jump.com/bcc/common/Talk3/OpenGLlabs/c262_lab08/c262_lab08.html a good site to refer to
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
    
    
## Things to do -- main()
1. In main(), find glutInitDisplayMode() and add GLUT_MULTISAMPLE:
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE );  
   Multisampling helps achieving full-screen antialiasing by averaging pixel colors on the edges of polygons. 
  
2. You need to enable multisampling to activate this feature:
    glEnable( GL_MULTISAMPLE );  
    
 

