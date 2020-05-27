#pragma once
class StageNumber : public IGameObject
{
public:
	StageNumber();
	~StageNumber();
	//ステージのステートを返す
	static StageNumber& GetInstance()
	{
		static StageNumber stageNo;
		return stageNo;
	}
	//ステ―ジのステート
	enum StageNo {
		enState_Stage1,
		enState_Stage2
	};
	//ステージ番号をセットする
	void SetStage(const StageNo& number)
	{
		m_stageNo = number;
	}
	//ステージ番号を返す
	StageNo GetStageNumber() const
	{
		return m_stageNo;
	}
	StageNo m_stageNo = enState_Stage1; //ステージNoの初期値
};

