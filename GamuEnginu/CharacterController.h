#pragma once
#include "A_Component.h"
#include "A_Entity.h"

namespace MyGameEngine
{
	class CharacterController : public A_Component
	{
	protected:
	public:
		CharacterController();
		~CharacterController();

		enum CharState {
			STAND,
			JUMP,
			RUN,
			WALK
		};

		void Awake() override;
		void Start() override;
		void Update(float deltaTime) override;
		void LateUpdate(float deltaTime) override;

		void SetEntity(A_Entity* entity) {
			this->entity = entity;
		}
		void setGrounded(bool grounded) {
			_isGrounded = grounded;
		}
	private:
		A_Entity *entity;
		CharState state;

		float _speed;
		bool _isGrounded = false;
		bool _againstLeftWall = false;
		bool _againstRightWall = false;
		bool _atCielling = false;
	};
}