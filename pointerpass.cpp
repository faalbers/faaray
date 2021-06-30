#include <memory>
#include <iostream>

class Camera
{
public:
    Camera() { std::cout << "Camera construct\n"; }
    ~Camera() { std::cout << "Camera deconstruct\n"; }
};

class PinHoleCamera : public Camera
{
public:
    PinHoleCamera() { std::cout << "PinHoleCamera construct\n"; }
    ~PinHoleCamera() { std::cout << "PinHoleCamera deconstruct\n"; }
};

class Scene
{
public:
    Scene() : cameraSPtr_(nullptr) { std::cout << "Scene construct\n"; }
    ~Scene() { std::cout << "Scene deconstruct\n"; }

    void setCamera(std::shared_ptr<Camera> cameraSPtr) { cameraSPtr_ = cameraSPtr; }
    void setCamera(Camera *cameraPtr) {
        std::shared_ptr<Camera> cameraSPtr(cameraPtr);
        cameraSPtr_ = cameraSPtr;
    }

private:
    std::shared_ptr<Camera> cameraSPtr_;

};

class RenderJob
{
public:
    RenderJob() : sceneSPtr_(new Scene) { std::cout << "RenderJob construct\n"; }
    ~RenderJob() { std::cout << "RenderJob deconstruct\n"; }

    std::shared_ptr<Scene>      getSceneSPtr() const { return sceneSPtr_; }

private:
    std::shared_ptr<Scene>      sceneSPtr_;

};

class MainWindow
{
public:
    MainWindow() { std::cout << "MainWindow construct\n"; }
    ~MainWindow() { std::cout << "MainWindow deconstruct\n"; }

    void render()
    {
        renderJobPtr_   = new RenderJob;

        std::cout << "start sceneBuild_\n";

        sceneBuild_();

        std::cout << "sceneBuild_ ended\n";
    }

    void renderDone()
    {
        delete renderJobPtr_;
    }


private:
    RenderJob   *renderJobPtr_;

    void sceneBuild_() const
    {
        Scene *scenePtr(renderJobPtr_->getSceneSPtr().get());

        //Use THIS system
        std::shared_ptr<PinHoleCamera>  cameraSPtr(new PinHoleCamera);
        scenePtr->setCamera(cameraSPtr);

        // Somehow Camera gets deconstructed, but not PinHoleCamera = memory leak
        // Do not use this system
        //PinHoleCamera *cameraPtr = new PinHoleCamera;
        //scenePtr->setCamera(cameraPtr);

    }
};

int main(int argc, char *argv[])
{
    std::cout << "start of main\n";

    MainWindow *mainWindowPtr = new MainWindow;

    std::cout << "start render\n";

    mainWindowPtr->render();

    std::cout << "render finished\n";
    std::cout << "start renderDone\n";

    mainWindowPtr->renderDone();

    //std::cout << "renderDone finished\n";

    delete mainWindowPtr;

    std::cout << "end of main\n";

    return 0;
}
