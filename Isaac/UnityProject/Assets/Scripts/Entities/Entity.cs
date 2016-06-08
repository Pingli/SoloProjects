using UnityEngine;

public class Entity : MonoBehaviour
{
	private struct MoveSpeed
	{
		public float AccelerationSpeed;
		public float Drag;
		public float HorizontalSpeed;
		public float VerticalSpeed;

		public Vector3 GetVelocity()
		{
			return new Vector3(HorizontalSpeed, 0, VerticalSpeed);
		}
	}

	private MoveSpeed _speedInfo;

	private void Awake()
	{
		SetAccelerationSpeed(0.02f);
		SetDrag(0.9f);
	}

	private void FixedUpdate ()
	{
		Vector3 change = new Vector3(_speedInfo.HorizontalSpeed, 0, _speedInfo.VerticalSpeed);
		transform.localPosition += change;
		_speedInfo.HorizontalSpeed *= _speedInfo.Drag;
		_speedInfo.VerticalSpeed *= _speedInfo.Drag;

	}

	protected void SetDrag(float value)
	{
		_speedInfo.Drag = value;
	}

	protected void SetAccelerationSpeed(float value)
	{
		_speedInfo.AccelerationSpeed = value;
	}

	protected void MoveVertical(float value)
	{
		_speedInfo.VerticalSpeed += value * _speedInfo.AccelerationSpeed;
	}

	protected void MoveHorizontal(float value)
	{
		_speedInfo.HorizontalSpeed += value * _speedInfo.AccelerationSpeed;
	}

	protected Vector3 GetVelocity()
	{
		return _speedInfo.GetVelocity();
	}
}
