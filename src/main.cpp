#include <SFML/Graphics.hpp>
#include "config.hh"
#include "Render/SfmlRenderTarget.hh"
#include "Tracer/BasicTracer.hh"
#include "Scene/BasicScene.hh"
#include "Camera/PerspectiveCamera.hh"
#include "Object/Sphere.hh"
#include "Material/BasicMaterial.hh"

int	main()
{
	sf::RenderWindow	app(sf::VideoMode(WIDTH, HEIGHT), "Raytracer");

	BasicTracer			tracer;
	BasicScene			scene(&tracer);
	SfmlRenderTarget	renderTarget(WIDTH, HEIGHT);
	PerspectiveCamera	perspectiveCamera(Vector3D(0.0), Vector3D(0.0, 0.0, 50.0), Vector3D(0.0, 1.0, 0.0));

	Sphere				sphere(10, Vector3D(0.0, 0.0, 50.0));
	BasicMaterial		material(Color::red);

	sphere.setMaterial(&material);
	scene.addObject(&sphere);

	perspectiveCamera.computeFrame();
	perspectiveCamera.renderScene(scene, renderTarget);
	renderTarget.update();

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
