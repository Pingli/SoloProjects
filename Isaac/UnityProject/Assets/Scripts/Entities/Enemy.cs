using UnityEngine;

public class Enemy : Entity
{
	public GameObject player;

	private void Update()
	{
		ChaseTarget(player);
	}

	private void ChaseTarget(GameObject target)
	{
		MoveTo(target.transform.position);

	}

	private void MoveTo(Vector3 position)
	{
		Vector3 dir = position - transform.position;
		float speed = 0.1f;
		Vector3 vel = dir.normalized*speed;
		transform.position += vel;
	}
}
