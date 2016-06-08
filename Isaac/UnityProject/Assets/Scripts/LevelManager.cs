using UnityEngine;
using System.IO;
using System.Collections.Generic;

public class LevelManager : MonoBehaviour
{
	private const float TileSize = 2;
	private const float TileHeight = 0;

	private Dictionary<string, GameObject> dict = new Dictionary<string, GameObject>();
	[SerializeField]
	private GameObject stonePrefab;


	private GameObject levelObject;
	private GameObject grassObject;
	private GameObject formationObject;


	private const string LevelPath = "/Levels/";
	private const string FileExtension = ".csv";

	private void Update()
	{
		if (Input.GetKeyDown(KeyCode.Y))
		{
			ClearLevel();
			LoadLevel("Level1");
		}
	}

	private void OnEnable ()
	{
		levelObject = new GameObject("Level");
		dict.Add("1", stonePrefab);
		LoadLevel("Level1");
	}

	public void ClearLevel()
	{
		foreach (Transform t in levelObject.transform)
		{
			Destroy(t.gameObject);
		}
	}

	public void LoadLevel(string fileName)
	{
		string fullPath = Application.streamingAssetsPath + LevelPath + fileName;
		if (!fileName.EndsWith(FileExtension))
		{
			fullPath += FileExtension;
		}
		var level = ReadLevelCsv(fullPath);

		for (int i = 0; i < level.Count; i++)
		{
			var row = level[i];
			for (int n = 0; n < row.Count; n++)
			{
				var tile = row[n];
				if (dict.ContainsKey(tile))
				{
					Vector3 position = new Vector3(TileSize * n, TileHeight, -(TileSize * i));
					SpawnTile(dict[tile], position);
				}
				else
				{
					Debug.Log("failed loading " + tile);
				}
			}
		}
	}

	public static List<List<string>> ReadLevelCsv(string fullPath)
	{
		StreamReader sr = new StreamReader(fullPath);
		List<List<string>> table = new List<List<string>>();
		string line;

		while (!sr.EndOfStream)
		{
			line = sr.ReadLine();
			string[] a = line.Split(',');
			List<string> row = new List<string>(a);
			table.Add(row);
		}
		return table;
	}

	private void SpawnTile(GameObject prefab, Vector3 position)
	{
		var rotation = Quaternion.identity;
		GameObject obj = Instantiate(prefab, position, rotation) as GameObject;
		obj.transform.parent = levelObject.transform;
	}
}
