{\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Times New Roman;}{\f1\fnil\fcharset0 Arial;}{\f2\fnil Consolas;}{\f3\fnil\fcharset0 Consolas;}{\f4\fnil\fcharset0 Calibri;}}
{\colortbl ;\red128\green128\blue128;\red255\green255\blue255;\red0\green0\blue0;\red163\green21\blue21;\red0\green0\blue255;\red43\green145\blue175;\red0\green128\blue128;\red0\green128\blue0;\red111\green0\blue138;\red0\green77\blue187;\red47\green79\blue79;}
{\*\generator Msftedit 5.41.21.2510;}\viewkind4\uc1\pard\sa200\sl276\slmult1\lang9\f0\fs24 Tran Nguyen\par
ADGP 215\par
\pard\sa200\sl276\slmult1\qc\b\fs40 Documentation\fs24\par
\fs36 Rendering Geometry\par
\fs24\par
\f1\fs32 Function Information\f0\fs24\par
\pard\sl276\slmult1 File\b0 : Source.cpp\par
Data members:\par
\tab Name: m_VBO\par
\tab Description: Vertex Buffer Object (unsigned int)\par
\tab Name: m_IBO\par
\tab Description: Index Buffer Object (unsigned int)\par
\tab Name: m_VAO\par
\tab Description: Vertex Array Object (unsigned int)\par
\tab Name: m_programID\par
\tab Description: to bind shader (unsigned int)\par
\par
Function: generateGrid\par
Parameters: unsigned int rows, unsigned int cols \par
Description: create a grid depend on how many rows and cols \par
Return: n/a\par
\par
Function: createShader\par
Parameters: n/a\par
Description: create the shader\par
Return: n/a\par
\par
Function: main\par
Parameters: n/a\par
Description: test the program\par
Return: return int\par
\par
\pard\sl276\slmult1\qc\b\f1\fs32 Implementation\par
\pard\sl276\slmult1\b0\f0\fs24\par
\b File\b0 : Source.cpp\par
\cf1\highlight2\f2 #include\cf3  \cf4 <vector>\cf3\par
\cf1 #include\cf3  \cf4 "stdio.h"\cf3\par
\cf1 #include\cf3  \cf4 <gl_core_4_4.h>\cf3\par
\cf1 #include\cf3  \cf4 <Gizmos.h>\cf3\par
\cf1 #include\cf3  \cf4 <GLFW/glfw3.h>\cf3  \par
\cf1 #include\cf3  \cf4 <glm\\glm.hpp>\cf3\par
\cf1 #include\cf3  \cf4 <glm\\ext.hpp>\cf3\par
\cf1 #include\cf3  \cf4 <iostream>\cf3\par
\cf1 #include\cf3  \cf4 "MyApplication.h"\cf3\par
\par
\cf5 using\cf3  glm::\cf6 vec3\cf3 ;\par
\cf5 using\cf3  glm::\cf6 vec4\cf3 ;\par
\cf5 using\cf3  glm::\cf6 mat4\cf3 ;\par
\par
\cf0\highlight0\f0 #Function: generateGrid\par
#Parameters: unsigned int rows, unsigned int cols \par
#Description: create a grid depend on how many rows and cols \par
#Return: n/a\par
\cf5\highlight2\f2\fs20 void\cf3  generateGrid(\cf5 unsigned\cf3  \cf5 int\cf3  \cf1 rows\cf3 , \cf5 unsigned\cf3  \cf5 int\cf3  \cf1 cols\cf3 )\par
\{\par
\tab\cf6 mat4\cf3  m_view = glm::lookAt(\cf6 vec3\cf3 (10, 10, 10), \cf6 vec3\cf3 (0), \cf6 vec3\cf3 (0, 1, 0));\par
\tab\cf6 mat4\cf3  m_projection = glm::perspective(glm::pi<\cf5 float\cf3 >()*0.25f, 16 / 9.f, \lang1033\f3\tab\tab\tab\tab\tab\tab\tab\tab\tab\tab\lang9\f2 0.1f, 1000.f);\par
\tab\cf6 mat4\cf3  m_projectionViewMatrix = m_projection \cf7 *\cf3  m_view;\par
\par
\tab\cf6 Vertex\cf3 * aoVertices = \cf7 new \cf6 Vertex\cf3 [\cf1 rows\cf3  * \cf1 cols\cf3 ];  \par
\tab\cf5 for\cf3  (\cf5 unsigned\cf3  \cf5 int\cf3  r = 0; r < \cf1 rows\cf3 ; ++r) \par
\tab\tab\cf5 for\cf3  (\cf5 unsigned\cf3  \cf5 int\cf3  c = 0; c < \cf1 cols\cf3 ; ++c) \par
\tab\tab\{\par
\tab\tab\lang1033\f3\tab\lang9\f2 aoVertices[r * \cf1 cols\cf3  + c].position \cf7 =\cf3  \cf6 vec4\cf3 ((\cf5 float\cf3 )c, 0, (\cf5 float\cf3 )\lang1033\f3\tab\tab\tab\tab\tab\tab\tab\tab\tab\tab\tab\lang9\f2 r, 1);\par
\tab\tab\tab                \par
\tab\tab\tab\cf6 vec3\cf3  colour = \cf6 vec3\cf3 ( sinf( (c / (\cf5 float\cf3 )(\cf1 cols\cf3  - 1)) * ( r / \lang1033\f3\tab\tab\tab\tab\tab\tab\tab\tab\tab\lang9\f2 (\cf5 float\cf3 )(\cf1 rows\cf3  - 1))) );       \par
\tab\tab\tab aoVertices[ r * \cf1 cols\cf3  + c ].colour \cf7 =\cf3  \cf6 vec4\cf3 ( 1,1,1,1 );   \par
\tab\tab\}\par
\par
\tab\cf5 unsigned\cf3  \cf5 int\cf3  *auiIndices = \cf7 new u\cf5 nsigned\cf3  \cf5 int\cf3 [(\cf1 rows\cf3  - 1) * (\cf1 cols\cf3  - 1) * 6];\par
\tab\cf5 unsigned\cf3  \cf5 int\cf3  index = 0; \par
\tab\cf5 for\cf3  (\cf5 unsigned\cf3  \cf5 int\cf3  r = 0; r < (\cf1 rows\cf3  - 1); ++r) \par
\tab\tab\cf5 for\cf3  (\cf5 unsigned\cf3  \cf5 int\cf3  c = 0; c < (\cf1 cols\cf3  - 1); ++c) \par
\tab\tab\{   \par
\tab\tab\tab\cf8 // triangle 1   \cf3\par
\tab\tab\tab auiIndices[ index++ ] = r * \cf1 cols\cf3  + c;   \par
\tab\tab\tab auiIndices[ index++ ] = (r + 1) * \cf1 cols\cf3  + c;   \par
\tab\tab\tab auiIndices[ index++ ] = (r + 1) * \cf1 cols\cf3  + (c + 1);\par
\par
\tab\tab\tab\cf8 // triangle 2   \cf3\par
\tab\tab\tab auiIndices[ index++ ] = r * \cf1 cols\cf3  + c;   \par
\tab\tab\tab auiIndices[ index++ ] = (r + 1) * \cf1 cols\cf3  + (c + 1);   \par
\tab\tab\tab auiIndices[ index++ ] = r * \cf1 cols\cf3  + (c + 1);  \par
\tab\tab\}\par
\par
\tab\cf9 glGenBuffers\cf3 (1, &m_VBO); \par
\tab\cf9 glGenBuffers\cf3 (1, &m_IBO);\par
\par
\tab\cf9 glGenVertexArrays\cf3 (1, &m_VAO);\par
\tab\cf9 glBindVertexArray\cf3 (m_VAO);\tab\par
\par
\tab\cf9 glBindBuffer\cf3 (\cf9 GL_ARRAY_BUFFER\cf3 , m_VBO);\par
\tab\cf9 glBindBuffer\cf3 (\cf9 GL_ELEMENT_ARRAY_BUFFER\cf3 , m_IBO);\par
\tab\cf9 glBufferData\cf3 (\cf9 GL_ARRAY_BUFFER\cf3 , (\cf1 rows\cf3  * \cf1 cols\cf3 ) * \cf5 sizeof\cf3 (\cf6 Vertex\cf3 ), aoVertices, \lang1033\f3\tab\tab\tab\tab\tab\tab\tab\tab\tab\tab\cf9\lang9\f2 GL_STATIC_DRAW\cf3 );\par
\tab\cf9 glBufferData\cf3 (\cf9 GL_ELEMENT_ARRAY_BUFFER\cf3 , (\cf1 rows\cf3  - 1) * (\cf1 cols\cf3  - 1) * 6 * \cf5 sizeof\lang1033\f3\tab\tab\tab\tab\tab\tab\cf3\lang9\f2 (\cf5 unsigned\cf3  \cf5 int\cf3 ), auiIndices, \cf9 GL_STATIC_DRAW\cf3 ); \par
\par
\tab\cf9 glEnableVertexAttribArray\cf3 (0); \par
\tab\cf9 glEnableVertexAttribArray\cf3 (1); \par
\tab\cf9 glVertexAttribPointer\cf3 (0, 4, \cf9 GL_FLOAT\cf3 , \cf9 GL_FALSE\cf3 , \cf5 sizeof\cf3 (\cf6 Vertex\cf3 ), 0); \par
\tab\cf9 glVertexAttribPointer\cf3 (1, 4, \cf9 GL_FLOAT\cf3 , \cf9 GL_FALSE\cf3 , \cf5 sizeof\cf3 (\cf6 Vertex\cf3 ), (\cf5 void\cf3 *)\lang1033\f3\tab\tab\tab\tab\tab\tab\tab\tab\tab\lang9\f2 (\cf5 sizeof\cf3 (\cf6 vec4\cf3 )));\par
\par
\tab\cf9 glBindVertexArray\cf3 (0);\par
\tab\cf9 glBindBuffer\cf3 (\cf9 GL_ELEMENT_ARRAY_BUFFER\cf3 , 0);\par
\tab\cf9 glBindBuffer\cf3 (\cf9 GL_ARRAY_BUFFER\cf3 , 0);\par
\par
\tab\cf9 glClearColor\cf3 (0.25f, 0.25f, 0.25f, 1);\par
\tab\cf9 glEnable\cf3 (\cf9 GL_DEPTH_TEST\cf3 );\par
\tab\cf9 glClear\cf3 (\cf9 GL_COLOR_BUFFER_BIT\cf3  | \cf9 GL_DEPTH_BUFFER_BIT\cf3 );\par
\par
\tab\cf9 glUseProgram\cf3 (m_programID);\par
\tab\cf5 unsigned\cf3  \cf5 int\cf3  projectionViewUniform = \cf9 glGetUniformLocation\cf3 (m_programID, \lang1033\f3\tab\tab\tab\tab\tab\tab\tab\tab\tab\tab\cf4\lang9\f2 "ProjectionView"\cf3 );\par
\tab\cf9 glUniformMatrix4fv\cf3 (projectionViewUniform, 1, \cf5 false\cf3 , glm::value_ptr\lang1033\f3\tab\tab\tab\tab\tab\tab\tab\tab\tab\tab\lang9\f2 (m_projectionViewMatrix));\par
\par
\tab\cf9 glBindVertexArray\cf3 (m_VAO);\par
\tab\cf5 unsigned\cf3  \cf5 int\cf3  indexCount = (\cf1 rows\cf3  - 1) * (\cf1 cols\cf3  - 1) * 6;\par
\tab\cf9 glPolygonMode\cf3 (\cf9 GL_FRONT_AND_BACK\cf3 , \cf9 GL_LINE\cf3 );\par
\tab\cf9 glDrawElements\cf3 (\cf9 GL_TRIANGLES\cf3 , indexCount, \cf9 GL_UNSIGNED_INT\cf3 , 0);\par
\par
\tab\cf8 // we\rquote ll do more here soon!  \cf3\par
\tab\cf10 delete\cf3 [] aoVertices; \par
\tab\cf10 delete\cf3 [] auiIndices;\par
\}\fs19\par
\par
\cf0\highlight0\f0\fs24 #Function: createShader\par
#Parameters: n/a\par
#Description: create the shader\par
#Return: n/a\cf3\highlight2\f2\fs19\par
\cf5\fs20 void\cf3  createShader()\par
\{\par
\tab\cf5 const\cf3  \cf5 char\cf3 * vsSource = \cf4 "#version 410\\n \\     \par
\lang1033\f3\tab\tab\tab\tab    \lang9\f2 layout(location=0) in vec4 Position; \\     \par
\lang1033\f3\tab\tab\tab\tab    \lang9\f2 layout(location=1) in vec4 Colour; \\     \par
\lang1033\f3\tab\tab\tab\tab    \lang9\f2 out vec4 vColour; \\     \par
\lang1033\f3\tab\tab\tab\tab    \lang9\f2 uniform mat4 ProjectionView; \\     \par
\lang1033\f3\tab\tab\tab\tab    \lang9\f2 void main() \{ vColour = Colour; gl_Position = \lang1033\f3\\\tab\tab\tab\tab\tab    \lang9\f2 ProjectionView * Position;\}"\cf3 ;\par
\par
\tab\cf5 const\cf3  \cf5 char\cf3 * fsSource = \cf4 "#version 410\\n \\     \par
\lang1033\f3\tab\tab\tab\tab     \lang9\f2 in vec4 vColour; \\     \par
\lang1033\f3\tab\tab\tab\tab     \lang9\f2 out vec4 FragColor; \\     \par
\lang1033\f3\tab\tab\tab\tab     \lang9\f2 void main() \{ FragColor = vColour; \}"\cf3 ;   \par
\par
\tab  \par
\tab\cf5 unsigned\cf3  \cf5 int\cf3  vertexShader = \cf9 glCreateShader\cf3 (\cf9 GL_VERTEX_SHADER\cf3 );\par
\tab\cf5 unsigned\cf3  \cf5 int\cf3  fragmentShader = \cf9 glCreateShader\cf3 (\cf9 GL_FRAGMENT_SHADER\cf3 );\par
\par
\tab\cf9 glShaderSource\cf3 (vertexShader, 1, (\cf5 const\cf3  \cf5 char\cf3 **)&vsSource, 0); \par
\tab\cf9 glCompileShader\cf3 (vertexShader);  \par
\tab\cf9 glShaderSource\cf3 (fragmentShader, 1, (\cf5 const\cf3  \cf5 char\cf3 **)&fsSource, 0); \par
\tab\cf9 glCompileShader\cf3 (fragmentShader);    \par
\par
\tab m_programID = \cf9 glCreateProgram\cf3 (); \par
\tab\cf9 glAttachShader\cf3 (m_programID, vertexShader);\par
\tab\cf9 glAttachShader\cf3 (m_programID, fragmentShader); \par
\tab\cf9 glBindAttribLocation\cf3 (0, m_programID, \cf4 "Position"\cf3 );\par
\tab\cf9 glBindAttribLocation\cf3 (1, m_programID, \cf4 "Colour"\cf3 );\par
\tab\cf9 glLinkProgram\cf3 (m_programID);  \par
\par
\tab\cf5 int\cf3  success = \cf9 GL_FALSE\cf3 ; \par
\tab\cf9 glGetProgramiv\cf3 (m_programID, \cf9 GL_LINK_STATUS\cf3 , &success); \par
\tab\cf5 if\cf3  (success == \cf9 GL_FALSE\cf3 ) \par
\tab\{ \par
\tab\tab\cf5 int\cf3  infoLogLength = 0;  \par
\tab\tab\cf9 glGetProgramiv\cf3 (m_programID, \cf9 GL_INFO_LOG_LENGTH\cf3 , &infoLogLength);  \par
\par
\tab\tab\cf5 char\cf3 * infoLog = \cf7 new c\cf5 har\cf3 [infoLogLength];     \par
\tab\tab\cf9 glGetProgramInfoLog\cf3 (m_programID, infoLogLength, 0, infoLog);  \par
\tab\tab printf(\cf4 "Error: Failed to link shader program!\\n"\cf3 );  \par
\tab\tab printf(\cf4 "%s\\n"\cf3 , infoLog);  \par
\par
\tab\tab\cf10 delete\cf3 [] infoLog; \par
\tab\}\par
\tab\par
\tab\cf9 glDeleteShader\cf3 (fragmentShader); \par
\tab\cf9 glDeleteShader\cf3 (vertexShader);\par
\}\fs19\par
\par
\cf0\highlight0\f0\fs24 #Function: main\par
#Parameters: n/a\par
#Description: test the program\par
#Return: return int\cf3\highlight2\f2\fs19\par
\cf5\fs20 int\cf3  main()\par
\{\par
\tab\cf5 if\cf3  (glfwInit() == \cf5 false\cf3 )\par
\tab\tab\cf5 return\cf3  -1;\par
\par
\tab\cf6 GLFWwindow\cf3  *window = glfwCreateWindow(1280, 720, \cf4 "Computer Graphics"\cf3 , \lang1033\f3\tab\tab\tab\tab\tab\tab\tab\tab\tab\tab\cf5\lang9\f2 nullptr\cf3 , \cf5 nullptr\cf3 );\par
\par
\tab\cf5 if\cf3  (window == \cf5 nullptr\cf3 )\par
\tab\{\par
\tab\tab glfwTerminate();\par
\tab\tab\cf5 return\cf3  -2;\par
\tab\}\par
\par
\tab glfwMakeContextCurrent(window);\par
\par
\tab\cf5 if\cf3  (ogl_LoadFunctions() == \cf11 ogl_LOAD_FAILED\cf3 )\par
\tab\{\par
\tab\tab glfwDestroyWindow(window);\par
\tab\tab glfwTerminate();\par
\tab\tab\cf5 return\cf3  -3;\par
\tab\}\par
\par
\tab\cf8 //testing what version of OpenGL we are running\cf3\par
\tab\cf5 auto\cf3  major = ogl_GetMajorVersion();\par
\tab\cf5 auto\cf3  minor = ogl_GetMinorVersion();\par
\tab printf_s(\cf4 "GL: %i.%i\\n"\cf3 , major, minor);\par
\par
\tab createShader();\par
\tab generateGrid(5, 5);\par
\par
\tab glfwSwapBuffers(window);\par
\tab glfwPollEvents();\par
\par
\tab system(\cf4 "pause"\cf3 );\par
\tab glfwDestroyWindow(window);\par
\tab glfwTerminate();\par
\tab\cf5 return\cf3  0;\par
\}\fs19\par
\par
\par
\cf0\highlight0\f4\fs22\par
}
 