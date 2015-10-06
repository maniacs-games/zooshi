// Copyright 2015 Google Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef FPL_COMPONENTS_ATTRIBUTES_H_
#define FPL_COMPONENTS_ATTRIBUTES_H_

#include "config_generated.h"
#include "attributes_generated.h"
#include "entity/component.h"

namespace fpl {

class InputSystem;
class AssetManager;
class FontManager;

namespace fpl_project {

// Data for scene object components.
class AttributesData {
 public:
  AttributesData() {
    for (int i = 0; i < AttributeDef_Size; ++i) {
      attributes[i] = 0;
    }
    // Start the game with a requirement of 20 points.
    // TODO: Move this into a data file.
    attributes[AttributeDef_TargetScore] = 20;
  }

  float attributes[AttributeDef_Size];
};

class AttributesComponent : public entity::Component<AttributesData> {
 public:
  virtual void Init();
  virtual void AddFromRawData(entity::EntityRef& entity, const void* raw_data);
  virtual RawDataUniquePtr ExportRawData(const entity::EntityRef& entity) const;
  virtual void InitEntity(entity::EntityRef& /*entity*/) {}

 private:
  InputSystem* input_system_;
  AssetManager* asset_manager_;
  FontManager* font_manager_;
};

}  // fpl_project
}  // fpl

FPL_ENTITY_REGISTER_COMPONENT(fpl::fpl_project::AttributesComponent,
                              fpl::fpl_project::AttributesData)

#endif  // FPL_COMPONENTS_ATTRIBUTES_H_
