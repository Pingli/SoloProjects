
using UnityEngine;

public class Player : Entity
{
	private void Start()
	{
		
	}
	
	private void Update()
	{
		Movement();
	}

	private void Movement()
	{
		float hor = Input.GetAxis("Horizontal");
		float ver = Input.GetAxis("Vertical");
		MoveHorizontal(hor);
		MoveVertical(ver);
	}
}
