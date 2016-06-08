
using UnityEngine;

public class Player : Entity
{
	[SerializeField]
	private GameObject tearPrefab;

	private void Start()
	{

	}

	private void Update()
	{
		Movement();
		if (Input.GetKeyDown(KeyCode.Space))
		{
			SpawnTear();
		}
	}

	private void SpawnTear()
	{
		GameObject obj = Instantiate(tearPrefab, transform.position + transform.forward, transform.rotation) as GameObject;
		Tear tear = obj.GetComponent<Tear>();
		tear.SetVelocity(GetVelocity());
	}

	private void Movement()
	{
		float hor = Input.GetAxis("Horizontal");
		float ver = Input.GetAxis("Vertical");
		MoveHorizontal(hor);
		MoveVertical(ver);
	}
}
