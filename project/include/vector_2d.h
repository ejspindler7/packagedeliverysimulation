/**
 *@file vector_2d.h
 */
#ifndef VECTOR_2D_H_
#define VECTOR_2D_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "vector_3d.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
  /**
   * @brief A class for 2D vectors and associated methods.
   *
   * Contains methods necessary to perform 2D vector math.
   */
  class Vector2D : public Vector3D {
    public:
      /**
       * @brief Component-wise Constructor.
       *  
       * @param x A float representing the x component of the vector. 
       * @param z A float representing the z component of the vector. 
       */ 
      Vector2D(float x = 0.0, float z = 0.0);

      /**
       * @brief vector<float> Constructor.
       *
       * Initializes to zero-vector if size of vec parameter is not 2 or 3.
       *  
       * @param vec A vector<float> object. If vec size is 2,
       *            the first element is interpreted as the x component, and
       *            the second element is interpreted as the z component.
       *            If the size is 3, the second element is ignored and the
       *            first and third elements are interpreted as the x and 
       *            z components respectively. If the size is anything else,
       *            the x and z components will be initialized to zero.
       */ 
      Vector2D(const std::vector<float>& vec);

      /**
       * @brief Set the x and z vector components. 
       *
       * @param x A float representing the x component of the vector.
       * @param z A float representing the z component of the vector.
       * @return void.
       */ 
      void SetComponents(float x, float z);

      /**
       * @brief Set the x and z vector components. 
       *
       * @param x A float representing the x component of the vector.
       * @param y Has no effect (the y component will always be 0 for
       *          Vector2D objects.
       * @param z A float representing the z component of the vector.
       * @return void.
       */ 
      void SetComponents(float x, float y, float z) override;

      /**
       * @brief Set the x and z vector components. 
       *
       * Has no effect is vec.size() is not 2 or 3.
       *
       * @param vec A vector<float> object of size 2 or 3. If size is 2,
       *            the first element is interpreted as the x component, and
       *            the second element is interpreted as the z component.
       *            If the size is 3, the second element is ignored and the
       *            first and third elements are interpreted as the x and 
       *            z components respectively.
       * @return void.
       */ 
      void SetComponents(const std::vector<float>& vec) override;
  };

} // namespace csci3081

#endif // VECTOR_2D_H_
