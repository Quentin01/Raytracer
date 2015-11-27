#include <SFML/Graphics.hpp>
#include "config.hh"
#include "Render/SfmlRenderTarget.hh"
#include "Tracer/BasicTracer.hh"
#include "Scene/BasicScene.hh"
#include "Camera/PerspectiveCamera.hh"
#include "Object/Sphere.hh"
#include "Material/BasicMaterial.hh"
#include "Light/AmbientLight.hh"

void buildAndRenderScene(Scene &scene, Camera &camera, RenderTarget &renderTarget)
{
    // Build scene
    AmbientLight        ambientLight(Color::white);
    Sphere              sphere(10, Vector3D(0.0, 0.0, 50.0));
    BasicMaterial       material(Color::red);

    sphere.setMaterial(&material);
    
    scene.addObject(&sphere);
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
    PerspectiveCamera   perspectiveCamera(Vector3D(0.0), Vector3D(0.0, 0.0, 50.0), Vector3D(0.0, 1.0, 0.0));

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
