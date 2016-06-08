using UnityEngine;

public class Entity : MonoBehaviour
{
	private struct MoveSpeed
	{
		public float HorizontalSpeed;
		public float VerticalSpeed;
	}

	private MoveSpeed _speedInfo;

	private void FixedUpdate ()
	{
		Vector3 change = new Vector3(_speedInfo.HorizontalSpeed, 0, _speedInfo.VerticalSpeed);
		transform.localPosition += change;
	}

	protected void MoveVertical(float value)
	{
		_speedInfo.VerticalSpeed = value;
	}

	protected void MoveHorizontal(float value)
	{
		_speedInfo.HorizontalSpeed = value;
	}
}
