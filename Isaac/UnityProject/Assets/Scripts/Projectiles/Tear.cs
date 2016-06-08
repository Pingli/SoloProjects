using UnityEngine;
using System.Collections;

public class Tear : MonoBehaviour
{
	private Vector3 velocity;

	[SerializeField]
	private float gravityStrengthMin;
	[SerializeField]
	private float gravityStrengthMax;

	private float currentGravityMod = 0;

	private void FixedUpdate()
	{
		transform.position += velocity;
		velocity = new Vector3(velocity.x, velocity.y - currentGravityMod, velocity.z);
	}

	public void SetVelocity(Vector3 vel)
	{
		velocity = vel;
	}

	private void OnCollisionEnter(Collision other)
	{
		if (other.transform.name == "Floor")
		{
			Destroy(gameObject);
		}
	}

}
