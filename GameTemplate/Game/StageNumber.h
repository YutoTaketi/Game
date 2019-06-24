#pragma once
class StageNumber : public IGameObject
{
public:
	StageNumber();
	~StageNumber();
	static StageNumber& GetInstance()
	{
		static StageNumber stageNo;
		return stageNo;
	}
	enum StageNo {
		enState_Stage1,
		enState_Stage2
	};
	void SetStage(const StageNo& number)
	{
		m_stageNo = number;
	}
	StageNo GetStageNumber() const
	{
		return m_stageNo;
	}
	StageNo m_stageNo = enState_Stage1;
};

