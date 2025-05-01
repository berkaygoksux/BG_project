#include <glad/glad.h>

unsigned int cubeVAO, cubeVBO, cubeEBO;
unsigned int planeVAO, planeVBO, planeEBO;
unsigned int swingVAO, swingVBO;

// --- Cube ---
void setupCube() {
    float vertices[] = {
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
    };
    unsigned int indices[] = {
        0,1,2, 2,3,0, 4,5,6, 6,7,4, 0,1,5, 5,4,0,
        2,3,7, 7,6,2, 0,3,7, 7,4,0, 1,2,6, 6,5,1
    };
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &cubeVBO);
    glGenBuffers(1, &cubeEBO);
    glBindVertexArray(cubeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

void drawCube() {
    glBindVertexArray(cubeVAO);
    glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
}

// --- Plane ---
void setupPlane() {
    float vertices[] = {
        -5.0f,0.0f,-5.0f,
         5.0f,0.0f,-5.0f,
         5.0f,0.0f,5.0f,
        -5.0f,0.0f,5.0f,
    };
    unsigned int indices[] = {0,1,2,2,3,0};
    glGenVertexArrays(1,&planeVAO);
    glGenBuffers(1,&planeVBO);
    glGenBuffers(1,&planeEBO);
    glBindVertexArray(planeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, planeEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

void drawPlane() {
    glBindVertexArray(planeVAO);
    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
}

// --- Swing (salıncak) ---
void setupSwing() {
    float swingLines[] = {
        -0.2f,0.0f,0.0f, -0.2f,1.0f,0.0f,  // sol dikme
         0.2f,0.0f,0.0f,  0.2f,1.0f,0.0f,  // sağ dikme
        -0.2f,1.0f,0.0f,  0.2f,1.0f,0.0f,  // üst bar
    };
    glGenVertexArrays(1,&swingVAO);
    glGenBuffers(1,&swingVBO);
    glBindVertexArray(swingVAO);
    glBindBuffer(GL_ARRAY_BUFFER, swingVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(swingLines), swingLines, GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

void drawSwing() {
    glBindVertexArray(swingVAO);
    glDrawArrays(GL_LINES,0,6);
    glBindVertexArray(0);
}

// --- Sphere (placeholder) ---
void setupSphere() {
    // Not: Burada basit bir sphere modeli veya glut çağrısı eklenebilir.
}

void drawSphere() {
    // Not: Sphere çizmek için hazır kütüphane veya low-poly küre kullanılabilir.
}
