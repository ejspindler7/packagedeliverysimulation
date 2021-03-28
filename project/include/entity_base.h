/**
 *@file entity_base.h
 */
#ifndef ENTITY_BASE_H_
#define ENTITY_BASE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "vector_3d.h"
#include "json_helper.h"
#include <EntityProject/facade/delivery_system.h>

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
  /**
   * @brief The base class for creating entities.
   *
   * This class can be used as the base for all entities in the delivery system.
   * Implements the IEntity interface.
   */
  class EntityBase : public IEntity {

    public:
      /**
       * @brief Constructor.
       *  
       * All entities get a unique ID. By default, EntityBase::IsDynamic() will
       * return false. For dynamic (moving) entities, the derived class
       * constructor should set dynamic_ to true. Information about the 
       * requested entity is extracted from the details parameter.
       *
       * @param details A picojson object containing requested enitity details. 
       */ 
      EntityBase(const picojson::object& details);

      /**
       * @brief Default Destructor.
       */ 
      virtual ~EntityBase(); 

      /**
       * @brief Get the entity ID. 
       *
       * @return enitity ID. 
       */ 
      int GetId() const override; 

      /**
       * @brief Get the entity's name. 
       *
       * @return entity name. 
       */ 
      const std::string& GetName() override; 

      /**
       * @brief Get the entity's position. 
       *
       * @return entity position as a vector<float>& of size 3 where elements
       *         0, 1, and 2 correspond to the entity's x, y, and z
       *         coordinates respectively.
       */ 
      const std::vector<float>& GetPosition() const override;

      /**
       * @brief Set the entity's position using vector<float>. 
       *
       * If position parameter is not of size 3, the position gets set to 
       * (0,0,0).
       *
       * @param position A vector<float> of size 3 where elements
       *         0, 1, and 2 correspond to the entity's x, y, and z
       *         coordinates respectively.
       * @return void
       */ 
      void SetPosition(std::vector<float> position);

      /**
       * @brief Set the entity's position using a Vector3D object. 
       *
       * @param position A Vector3D object. 
       * @return void
       */ 
      void SetPosition(Vector3D position);

      /**
       * @brief Get the entity's direction. 
       *
       * @return entity direction as a vector<float>& of size 3 where elements
       *         0, 1, and 2 correspond to the entity's x, y, and z
       *         coordinates respectively.
       */ 
      const std::vector<float>& GetDirection() const override;

      /**
       * @brief Set the entity's direction using a Vector3D object. 
       *
       * @param direction A Vector3D reference. 
       * @return void
       */ 
      void SetDirection(const Vector3D& direction);

      /**
       * @brief Get the entity's radius. 
       *
       * The radius is used to determine entity's sphere of influence. If, for
       * example, the distance to another entity is less than the value of
       * radius, they may interact (ex. a drone might pick up a package).
       *
       * @return entity radius as a float. 
       */ 
      float GetRadius() const override;

      /**
       * @brief Get a copy of the details used to create the entity. 
       *
       * The details include information such as mesh, scale, rotation, initial
       * position name, type, etc.
       *
       * @return entity's initial details. 
       */ 
      const picojson::object& GetDetails() override; 

      /**
       * @brief Get the entity version. 
       *
       * Anytime an entity's variable other than position or direction has
       * changed, the version is incremented.
       *
       * @return entity version. 
       */ 
      int GetVersion() const override;

      /**
       * @brief Determine if the entity is static (stationary) or moving. 
       *
       * Used to improve visualization efficiency; static entities do not need
       * to be graphically updated as frequently.
       *
       * @return true when entity position/direction should be updated in
       *         the visualization. Returns false when entity should be 
       *         static.
       */ 
      bool IsDynamic() const override;

      /**
       * @brief Update entity as either dynamic or static. 
       *
       * Updates version if dynamic state changes: See EntityBase::GetVersion()
       * and EntityBase::IsDynamic(). 
       * 
       * @param dynamic A boolean that indicates whether the entity should
                        be dynamic (true) or not (false). 
       * @return void. 
       */ 
      void SetDynamic(bool dynamic);

    protected:
      int id_;
      std::string name_;
      Vector3D position_;
      Vector3D direction_;
      float radius_;
      picojson::object details_;
      int version_;
      bool dynamic_;

    private:
      static int next_id_;
  };

}  // namespace csci3081

#endif  // ENTITY_BASE_H_
