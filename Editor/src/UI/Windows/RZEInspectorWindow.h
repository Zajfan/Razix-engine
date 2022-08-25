#pragma once

#include <QFrame>
#include <QVBoxLayout>

#include "generated/ui_RZEInspectorWindow.h"

#include "RZESceneHierarchyPanel.h"

#include "UI/Widgets/ComponentsUI/RZETransformComponentUI.h"
#include "UI/Widgets/ComponentsUI/RZECameraComponentUI.h"

// All components will be added to this window and will be enabled on a need to basis; We can remove or add (only single isntance for now)
// This way code and design get's easier, but the Component widgets will have seperate UI and class files for ease of management;
// Will deriving from a common RZComponent and RZEComponentUI will benefit with plugin development and reduce code duplication? If so Implement it
namespace Razix {
    namespace Editor {
        class RZEInspectorWindow : public QFrame
        {
            Q_OBJECT

        public:
            RZEInspectorWindow(RZESceneHierarchyPanel* hierarchyPanel, QFrame* parent = nullptr);
            ~RZEInspectorWindow();

            QVBoxLayout& getBoxLayout() { return *(ui.verticalLayout_2); }

        public slots:
            void OnNameEdit();
            void OnEntitySelected(RZEntity entity);

        private:
            Ui::InspectorWindow ui;
            RZEntity            entity;
            // Hold the components here
            RZETransformComponentUI* m_TrasformComponentUI;
            RZECameraComponentUI*    m_CameraComponentUI;
        };
    }    // namespace Editor
}    // namespace Razix