/**
 *@file vector_3d.h
 */
#ifndef VECTOR_3D_H_
#define VECTOR_3D_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
  /**
   * @brief A class for 3D vectors and associated methods.
   *
   * Contains methods necessary to perform 3D vector math. Each vector has
   * three components (3-dimensions): x, y, and z.
   */
  class Vector3D {
    public:
      /**
       * @brief Component-wise Constructor.
       *  
       * @param x A float representing the x component of the vector. 
       * @param y A float representing the y component of the vector. 
       * @param z A float representing the z component of the vector. 
       */ 
      Vector3D(float x = 0.0, float y = 0.0, float z = 0.0);

      /**
       * @brief vector<float> Constructor.
       *
       * Initializes to zero-vector if size of vec parameter is not 3.
       *  
       * @param vec A vector<float> object of size 3. The first, second, and
       *            third elements of vec are interpreted as the x, y, and z
       *            vector components respectively. If size is not 3 then the
       *            Vector3D object is initialized to the zero-vector.
       */ 
      Vector3D(const std::vector<float>& vec);

      /**
       * @brief Get the x component of the vector. 
       *
       * @return x component of the vector. 
       */ 
      float GetX() const;

      /**
       * @brief Set the x component of the vector. 
       *
       * @param x A float that is to be the new x component of the vector.
       * @return Void.
       */ 
      void SetX(float x);

      /**
       * @brief Get the y component of the vector. 
       *
       * @return y component of the vector. 
       */ 
      float GetY() const;

      /**
       * @brief Set the y component of the vector. 
       *
       * @param y A float that is to be the new y component of the vector.
       * @return Void.
       */ 
      void SetY(float y);

      /**
       * @brief Get the z component of the vector. 
       *
       * @return z component of the vector. 
       */ 
      float GetZ() const;

      /**
       * @brief Set the z component of the vector. 
       *
       * @param z A float that is to be the new z component of the vector.
       * @return Void.
       */ 
      void SetZ(float z);

      /**
       * @brief Get the x,y, and z components of the vector in a vector<float>
       *        container of size 3.
       *
       * @return A vector<float> of size 3 with the x, y, and z components of
       *         the vector.
       */ 
      const std::vector<float>& GetComponents() const;

      /**
       * @brief Set the x, y, and z components of the vector. 
       *
       * @param x A float representing the x component of the vector.
       * @param y A float representing the y component of the vector.
       * @param z A float representing the z component of the vector.
       * @return void.
       */ 
      virtual void SetComponents(float x, float y, float z);

      /**
       * @brief Set the x, y, and z components of the vector. 
       *
       * Has no effect is vec.size() is not 3.
       *
       * @param vec A vector<float> object of size 3. The first, second, and
       *            third elements of vec are interpreted as the x, y, and z
       *            vector components respectively. 
       * @return void.
       */ 
      virtual void SetComponents(const std::vector<float>& vec);

      /**
       * @brief Update the vector to have a magnitude of 1 (unit-vector) without
       *        changing its direction. 
       *
       * @return A reference to the modified Vector3D (this).
       */ 
      Vector3D& Normalize();

      /**
       * @brief Scale the current vector.
       *
       * @param k A float to scale each component of the vector by.
       * @return A reference to the modified Vector3D (this).
       */ 
      Vector3D& Scale(float k);

      /**
       * @brief Get the vector's magnitude. 
       *
       * @return A float equal to the current vector's magnitude (length).
       */ 
      float Magnitude();

      /**
       * @brief Scale vector by -1 (reverses vector's direction). 
       *
       * @return void.
       */ 
      Vector3D& ReverseDirection();

      /**
       * @brief Perform a dot product operation with the provided vector.
       *
       * The resulting float is equal to 
       * (this.x * vec.x) + (this.z * vec.y) + (this.z * vec.z).
       *
       * @param vec A Vector3D reference to use in dot product operation
       *            alongside the current vector.
       * @return A float equal to the dot product.
       */ 
      float DotProduct(const Vector3D& vec);

      /**
       * @brief Perform a cross product operation with the provided vector.
       *
       * Results in a vector orthogonal to the plane spanned by the current
       * vector and the provided vector.
       *
       * @param vec A Vector3D reference to use in the cross product operation
       *            alongside the current vector.
       * @return A vector orthogonal to the plane spanned by the current vector
       *         and the provided vector.
       */ 
      Vector3D CrossProduct(const Vector3D& vec);

      /**
       * @brief Element-wise additon of two vectors.
       *
       * @param rhs A Vector3D reference to use in the addition operation
       *            alongside the current vector.
       * @return A vector equal to the element-wise addition of the current
       *         vector and rhs.
       */ 
      Vector3D operator+(const Vector3D& rhs);

      /**
       * @brief Element-wise difference of two vectors.
       *
       * @param rhs A Vector3D reference to use in the difference operation
       *            alongside the current vector.
       * @return A vector equal to the element-wise difference of the current
       *         vector and rhs.
       */ 
      Vector3D operator-(const Vector3D& rhs);

      /**
       * @brief Element-wise float equality of two vectors.
       *
       * Checks to see if each component of the two vectors are within
       * `epsilon = 0.0001` of each other. 
       * 
       * @param rhs A Vector3D reference to use in the equality check 
       *            alongside the current vector.
       * @return true if each component of the vectors differ by less than
       *         0.0001. false otherwise.
       */ 
      bool operator==(const Vector3D& rhs);

    private: 
      std::vector<float> xyz_components_;
  };

} // namespace csci3081

#endif // VECTOR_3D_H_
