#include <SFML/Graphics.hpp>
#include "config.hh"
#include "Render/SfmlRenderTarget.hh"
#include "Tracer/BasicTracer.hh"
#include "Scene/BasicScene.hh"
#include "Camera/PerspectiveCamera.hh"
#include "Object/Sphere.hh"
#include "Object/Plane.hh"
#include "Object/Torus.hh"
#include "Material/BasicMaterial.hh"
#include "Material/PhongMaterial.hh"
#include "Light/AmbientLight.hh"
#include "Light/PointLight.hh"

void buildAndRenderScene(Scene &scene, Camera &camera, RenderTarget &renderTarget)
{
    // Build scene
    AmbientLight        ambientLight(Color::white);
    PointLight          light1(Vector3D(50.0, 70.0, 0.0));
    PointLight          light2(Vector3D(50.0, 70.0, 200.0));

    Torus               sphere1(10, 4, Vector3D(0.0, 20.0, 100.0));
    PhongMaterial       material1(Color::red);

    Sphere              sphere2(10, Vector3D(0.0, 45.0, 100.0));
    PhongMaterial       material2(Color::green);

    Sphere              sphere3(10, Vector3D(35.0, 20.0, 100.0));
    PhongMaterial       material3(Color::blue);

    Plane               plane1(Vector3D(0, 0, 0), Vector3D(0.0, 1.0, 0.0));
    PhongMaterial       material4(Color(0.0, 1.0, 1.0));

    Plane               plane2(Vector3D(-100, 0, 0), Vector3D(1.0, 0.0, 0.0));
    PhongMaterial       material5(Color(1.0, 0.0, 1.0));

    Plane               plane3(Vector3D(0, 0, 500), Vector3D(0.0, 0.0, -1.0));
    PhongMaterial       material6(Color(1.0, 1.0, 0.0));

    sphere1.setMaterial(&material1);
    sphere2.setMaterial(&material2);
    sphere3.setMaterial(&material3);
    plane1.setMaterial(&material4);
    plane2.setMaterial(&material5);
    plane3.setMaterial(&material6);
    
    scene.addObject(&sphere1);
    scene.addObject(&sphere2);
    scene.addObject(&sphere3);
    scene.addObject(&plane1);
    scene.addObject(&plane2);
    scene.addObject(&plane3);

    scene.addLight(&light1);
    scene.addLight(&light2);
    scene.setAmbientLight(&ambientLight);

    // Render scene
    camera.computeFrame();
    camera.renderScene(scene, renderTarget);
    renderTarget.update();
}

int main()
{
    sf::RenderWindow    app(sf::VideoMode(WIDTH, HEIGHT), "Raytracer");

    BasicTracer         tracer;
    BasicScene          scene(&tracer);
    SfmlRenderTarget    renderTarget(WIDTH, HEIGHT);
    PerspectiveCamera   perspectiveCamera(Vector3D(0.0, 50.0, 0.0), Vector3D(0.0, 20.0, 100.0), Vector3D(0.0, -1.0, 0.0));

    buildAndRenderScene(scene, perspectiveCamera, renderTarget);

    while (app.isOpen())
    {
        sf::Event Event;

        while (app.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
                app.close();
        }

        app.clear();
        app.draw(renderTarget);
        app.display();
    }
  
    return (0);
}
