#ifndef ESP_H
#define ESP_H

#define RAD2DEG(x) ((float)(x) * (float)(180.f / IM_PI))
#define DEG2RAD(x) ((float)(x) * (float)(IM_PI / 180.f))

ImU32 color = IM_COL32(255, 255, 255, 150);

static inline ImVec2 operator*(const ImVec2& lhs, const float rhs) { return ImVec2(lhs.x * rhs, lhs.y * rhs); }
static inline ImVec2 operator/(const ImVec2& lhs, const float rhs) { return ImVec2(lhs.x / rhs, lhs.y / rhs); }
static inline ImVec2 operator+(const ImVec2& lhs, const float rhs) { return ImVec2(lhs.x + rhs, lhs.y + rhs); }
static inline ImVec2 operator+(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x + rhs.x, lhs.y + rhs.y); }
static inline ImVec2 operator-(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x - rhs.x, lhs.y - rhs.y); }
static inline ImVec2 operator-(const ImVec2& lhs, const float rhs) { return ImVec2(lhs.x - rhs, lhs.y - rhs); }
static inline ImVec2 operator*(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x * rhs.x, lhs.y * rhs.y); }
static inline ImVec2 operator/(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x / rhs.x, lhs.y / rhs.y); }
static inline ImVec2& operator*=(ImVec2& lhs, const float rhs) {
    lhs.x *= rhs;
    lhs.y *= rhs;
    return lhs;
}
static inline ImVec2& operator/=(ImVec2& lhs, const float rhs) {
    lhs.x /= rhs;
    lhs.y /= rhs;
    return lhs;
}
static inline ImVec2& operator+=(ImVec2& lhs, const ImVec2& rhs) {
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}
static inline ImVec2& operator-=(ImVec2& lhs, const ImVec2& rhs) {
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return lhs;
}
static inline ImVec2& operator*=(ImVec2& lhs, const ImVec2& rhs) {
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    return lhs;
}
static inline ImVec2& operator/=(ImVec2& lhs, const ImVec2& rhs) {
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;
    return lhs;
}
static inline ImVec4 operator+(const ImVec4& lhs, const ImVec4& rhs) { return ImVec4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w); }
static inline ImVec4 operator-(const ImVec4& lhs, const ImVec4& rhs) { return ImVec4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w); }
static inline ImVec4 operator*(const ImVec4& lhs, const ImVec4& rhs) { return ImVec4(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w); }

template <typename T>
inline T clamp(const T& n, const T& lower, const T& upper) {
    return std::max(lower, std::min(n, upper));
}


inline float lerp(float a, float b, float f) { return clamp<float>(a + f * (b - a), a > b ? b : a, a > b ? a : b); }

inline ImColor collerp(ImColor a, ImColor b, float f) { return {a.Value.x + f * (b.Value.x - a.Value.x), a.Value.y + f * (b.Value.y - a.Value.y), a.Value.z + f * (b.Value.z - a.Value.z), a.Value.w + f * (b.Value.w - a.Value.w)}; }

static bool ESPEnable = false, ESPLine = false, ESPBox = false, ESP2DBox = false, ESP3DBox = false, ESP3DBox2 = false, Fov = false;

static bool ESPCount = false, ESPArrow = false, ESPArrow2 = false, ESPHealth = false, ESPHealth2 = false, ESPName = false;
float colorEsp[3] = {255,255,255};
static bool ESPOutline = false, ESPDistance = false, ESPDistance2 = false, RS = false;

static bool setname = true;

static void *Current_Local_Player() {
    void *(*_Local_Player)(void *players) = (void *(*)(void *))getRealOffset(0x1024264E0);  
    return _Local_Player(NULL);
}

static monoString *U3DStr(const char *str) {
    monoString *(*String_CreateString)(void *_this, const char *str) = (monoString * (*)(void *, const char *))getRealOffset(0x1060775D0);  
    return String_CreateString(NULL, str);
}

static void spofNick(void *players) {
void (*_spof_nick)(void *player, monoString *nick) = (void (*)(void *, monoString *))getRealOffset(0x105258CE0);    
_spof_nick(players, U3DStr(ENCRYPTHEX("[FF33CC]Make [99FF00]Menu [7FFF00]Inbox: [CC34BA]VDuc [FF0000]Zalo: [00FFFF]0987779469[99FF00]")));
}

static float sliderDistanceValue = 300.0f;
static float AimbotFOV = 90.0f; 
int AimCheck = 0;
int AimType = 0;
int AimWhen = 1;
bool aim180;
float AimDis;
bool Enable = true;
bool isAiming = false; // Biến cờ để kiểm tra xem đang aim vào mục tiêu nào không
void* (*get_main)();
void* (*get_transform)(void*);
Vector3 (*WorldToViewpoint)(void*, Vector3, int);
Vector3 (*get_position)(void*);


ImVec2 world2screen_i(Vector3 pos) {
    auto cam = get_main();
    if (!cam) return {0, 0};

    Vector3 worldPoint = WorldToViewpoint(cam, pos, 2);
    Vector3 location;

    int ScreenWidth = ImGui::GetIO().DisplaySize.x;
    int ScreenHeight = ImGui::GetIO().DisplaySize.y;

    location.x = ScreenWidth * worldPoint.x;
    location.y = ScreenHeight - worldPoint.y * ScreenHeight;
    location.z = worldPoint.z;

    return {location.x, location.y};
}

ImVec2 world2screen_c(Vector3 pos, bool& checker) {
    auto cam = get_main();
    if (!cam) return {0, 0};

    Vector3 worldPoint = WorldToViewpoint(cam, pos, 2);
    Vector3 location;

    int ScreenWidth = ImGui::GetIO().DisplaySize.x;
    int ScreenHeight = ImGui::GetIO().DisplaySize.y;

    location.x = ScreenWidth * worldPoint.x;
    location.y = ScreenHeight - worldPoint.y * ScreenHeight;
    location.z = worldPoint.z;

    checker = location.z > 1;
    return {location.x, location.y};
}

int (*get_CurHP)(void* player);
bool get_isLiving(void* player) {
    if (get_CurHP(player) > 0) {
        return true;
    } else {
        return false;
    }
}

bool (*Team)(void*);
bool IsTeammate(void* player) {
    if (Team && player) {
        return Team(player);
    }
    return false;
}

bool (*Local)(void*);
bool IsLocalPlayer(void* player) {
    if (Local && player) {
        return Local(player);
    }
    return false;
}

int (*get_MaxHP)(void* player);

monoString* get_Nickname(void* player) {
    monoString* (*nickname)(void* instance) = (monoString * (*)(void*)) getRealOffset(ENCRYPTOFFSET("0x105258C80")); //   public string get_NickName() { }   VA *****1/18*****
    return nickname(player);  
}
std::string monoStringToStdString(monoString* mStr) {
    if (mStr == nullptr) return "";
    return std::string(mStr->toCString());
}

std::string getPlayerNickname(void* player) {
    if (player == nullptr) return "";
    monoString* mStr = get_Nickname(player);
    return monoStringToStdString(mStr);
}

bool get_IsDieing(void* player) {
    bool (*Dieing)(void* instance) = (bool (*)(void*))getRealOffset(ENCRYPTOFFSET("0x1052524C4")); //đã gục
    return Dieing(player);
}


bool get_IsVisible(void* player) {
    bool (*IsVisible)(void* instance) = (bool (*)(void*))getRealOffset(ENCRYPTOFFSET("0x1052602E0"));  //   public override bool IsVisible() { }  VA  ******1/6******
    return IsVisible(player);
}

static void *GetLocalPlayer(void* Game) {
    void *(*_GetLocalPlayer)(void *match) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x102B19008")); //   private static Player GetLocalPlayer() { } 0x102A00590
    return _GetLocalPlayer(Game);
}

static void *Curent_Match() {
    void *(*_Curent_Match) (void *nuls) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x102426010"));  //   public static NFJPHMKKEBF CurrentMatch() { }
    return _Curent_Match(NULL);
}

static void *Camera_main() {
    void *(*_Camera_main)(void *nuls) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x105EF6D08"));  //   public static Camera get_main() { }
    return _Camera_main(nullptr);
}

static Quaternion GetRotation(void* player) {
    Quaternion (*_GetRotation)(void* players) = (Quaternion(*)(void *))getRealOffset(ENCRYPTOFFSET("0x105F3D744"));  //   public Quaternion get_rotation() { }  *****2/16*****
    return _GetRotation(player);
}


static bool get_isLocalTeam(void *player) {
    bool (*_get_isLocalTeam)(void *players) = (bool (*)(void *))getRealOffset(ENCRYPTOFFSET("0x10526D118"));
    return _get_isLocalTeam(player);
}

static bool get_IsSighting(void *player) {
    bool (*_get_IsSighting)(void *players) = (bool (*)(void *))getRealOffset(ENCRYPTOFFSET("0x105252B44"));  //   public bool get_IsSighting() { }
    return _get_IsSighting(player);
}

static bool get_IsFiring(void *player) {
    bool (*_get_IsFiring)(void *players) = (bool (*)(void *))getRealOffset(ENCRYPTOFFSET("0x105252A90"));  //   public bool IsFiring() { }
    return _get_IsFiring(player);
}


static Vector3 WorldToScreenPoint(void *WorldCam, Vector3 WorldPos) {
    Vector3 (*_WorldToScreenScene)(void* Camera, Vector3 position) = (Vector3 (*)(void*, Vector3)) getRealOffset(ENCRYPTOFFSET("0x105EF6610"));  //   public Vector3 WorldToScreenPoint(Vector3 position, Camera.MonoOrStereoscopicEye eye) { }
    return _WorldToScreenScene(WorldCam, WorldPos);
}

static void *GetHeadPositions(void *player) {
    void *(*_GetHeadPositions)(void *players) = (void*(*)(void *))getRealOffset(ENCRYPTOFFSET("0x1052BECB8"));  //   public virtual Transform GetHeadTF() { }
     return _GetHeadPositions(player);
}


static Vector3 GetHeadPosition(void* player) {
    return get_position(GetHeadPositions(player));
}

static Vector3 CameraMain(void* player){
    return get_position(*(void**) ((uint64_t) player + 0x200));  //   public Transform MainCameraTransform; // 0x1C8
}


static void *Component_GetTransform(void *player) {
    void *(*_Component_GetTransform)(void *component) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x105EF8D78"));  //   public Transform get_transform() { }
    return _Component_GetTransform(player);
}


Vector3 getPosition(void *transform) {
    return get_position(Component_GetTransform(transform));
}   

static Vector3 GetForward(void *player) {
    Vector3 (*_GetForward)(void *players) = (Vector3 (*)(void *))getRealOffset(ENCRYPTOFFSET("0x105F3DE1C"));  // public Vector3 get_forward() { }  
    return _GetForward(player);
}

bool isFov(Vector3 vec1, Vector3 vec2, float diameter) {
    int x = vec1.x;
    int y = vec1.y;

    int x0 = vec2.x;
    int y0 = vec2.y;

    float radius = diameter / 2.0f; // Tính toán bán kính từ đường kính

    if ((pow(x - x0, 2) + pow(y - y0, 2)) <= pow(radius, 2)) {
        return true;
    } else {
        return false;
    }
}


std::vector<void*> players;
void clearPlayers() {
    if (!players.empty()) {
        std::vector<void*> pls;
        for (int i = 0; i < players.size(); i++) {
            if (players[i] != NULL && get_isLiving(players[i])) {
                pls.push_back(players[i]);
            }
        }
        players = pls;
    }
}

bool playerFind(void* pl) {
    if (pl != NULL) {
        for (int i = 0; i < players.size(); i++) {
            if (pl == players[i]) return true;
        }
    }
    return false;
}

Vector3 GetPlayerLocation(void* player) {
    Vector3 location;
    location = get_position(get_transform(player));
    return location;
}

bool IsClientBot(void* _this) { return *(bool*)((uint64_t)_this + 0x2B0); }

void (*old_Update)(void *player);
void Update(void* player) {
    if (player) {
        if (ESPEnable) {
            if (get_isLiving(player) && !Team(player)) {
                if (!playerFind(player)) players.push_back(player);
                clearPlayers();
                void* localplayers = Current_Local_Player();
                if (localplayers != NULL) {
                spofNick(localplayers);
                }
            }
        }

    }
    // old_Update(player);
}

void (*old_OnDestroy)(void *player);
void OnDestroy(void* player) {
    if (player != NULL) {
        auto it = std::find(players.begin(), players.end(), player);
        if (it != players.end()) {
            players.erase(it);
        }
    }
    // old_OnDestroy(player);
}

static void *Player_GetHeadCollider(void *player) {
    void *(*_Player_GetHeadCollider)(void *players) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x10525B768"));
    return _Player_GetHeadCollider(player);
}


static Vector3 Transform_GetPosition(void *player) {
    Vector3 out = Vector3::Zero();
    void (*_Transform_GetPosition)(void *transform, Vector3 * out) = (void (*)(void *, Vector3 *))getRealOffset(ENCRYPTOFFSET("0x105F3D49C"));
    _Transform_GetPosition(player, &out);
    return out;
}


static bool Physics_Raycast(Vector3 camLocation, Vector3 headLocation, unsigned int LayerID, void* collider) {
    bool (*_Physics_Raycast)(Vector3 camLocation, Vector3 headLocation, unsigned int LayerID, void* collider) = (bool(*)(Vector3, Vector3, unsigned int, void*))getRealOffset(ENCRYPTOFFSET("0x104BBB258"));  //   public static bool PLDCHDBCOBF(Vector3 OOFIJHADLNI, Vector3 CHGADBAMMOP, uint ONEDHFJBCMJ, ref MADMMIICBNN JEEIBOEGGPD) { }
    return _Physics_Raycast(camLocation, headLocation, LayerID, collider);
}
bool IsVisible(void * player){
    if(player != NULL) {
        void *hitObj = NULL;
        Vector3 cameraLocation = Transform_GetPosition(Component_GetTransform(Camera_main()));
        Vector3 headLocation = Transform_GetPosition(Component_GetTransform(Player_GetHeadCollider(player)));
            return !Physics_Raycast(cameraLocation, headLocation, 12, &hitObj);
    }
    return false;
}


Quaternion GetRotationToLocation(Vector3 targetLocation, float y_bias, Vector3 myLoc) {
    Vector3 direction = (targetLocation + Vector3(0, y_bias, 0)) - myLoc;
    return Quaternion::LookRotation(direction, Vector3::Up());
}

static void set_aim(void *player, Quaternion look) {
    void (*_set_aim)(void *players, Quaternion lock) = (void (*)(void *, Quaternion))getRealOffset(ENCRYPTOFFSET("0x10525CD8C")); 
    _set_aim(player, look);
}

void* targetEnemy = nullptr; // Biến lưu trữ enemy đang được nhắm
static float lastTargetChangeTime = 0.0f;

// Hàm kiểm tra xem mục tiêu có nằm trong tầm nhìn của người chơi không
bool IsTargetInPlayerView(void* player, void* target) {
    Vector3 playerForward = GetForward(Component_GetTransform(Camera_main())); // Hướng nhìn của người chơi
    Vector3 playerToTarget = Vector3::Normalized(GetHeadPosition(target) - CameraMain(player)); // Vector hướng từ người chơi đến mục tiêu
    float angle = RAD2DEG(acos(Vector3::Dot(playerForward, playerToTarget))); // Góc giữa hướng nhìn và vector hướng đến mục tiêu

    return angle <= AimbotFOV / 6.0f; // Kiểm tra xem góc có nằm trong FOV không
}

void Draw3DBox(Vector3 pos, void* player) {
    // Định nghĩa các đỉnh của hộp 3D tương đối với vị trí của người chơi
    Vector3 boxVertices[8] = {
        pos + Vector3(-0.4f, 1.9f, -0.4f), // Trên-trái-trước
        pos + Vector3(0.4f, 1.9f, -0.4f), // Trên-phải-trước
        pos + Vector3(0.4f, 1.9f, 0.4f), // Trên-phải-sau
        pos + Vector3(-0.4f, 1.9f, 0.4f), // Trên-trái-sau
        pos + Vector3(-0.4f, -0.15f, -0.4f), // Dưới-trái-trước
        pos + Vector3(0.4f, -0.15f, -0.4f), // Dưới-phải-trước
        pos + Vector3(0.4f, -0.15f, 0.4f), // Dưới-phải-sau
        pos + Vector3(-0.4f, -0.15f, 0.4f) // Dưới-trái-sau
    };

    ImVec2 screenVertices[8];
    bool w2sCheck[8];

    for (int i = 0; i < 8; i++) {
        screenVertices[i] = world2screen_i(boxVertices[i]);
        w2sCheck[i] = (screenVertices[i].x >= 0 && screenVertices[i].y >= 0);
    }
    if (targetEnemy != nullptr && targetEnemy == player && IsVisible(targetEnemy)) { ImColor(0, 0, 255); // Đổi thành màu xanh nếu là mục tiêu Aimbot và đang nhìn thấy
    }

    // Vẽ các cạnh của hộp 3D
       if (w2sCheck[0] && w2sCheck[1]) ImGui::GetBackgroundDrawList()->AddLine(screenVertices[0], screenVertices[1], ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 1.0);
    if (w2sCheck[1] && w2sCheck[2]) ImGui::GetBackgroundDrawList()->AddLine(screenVertices[1], screenVertices[2], ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 1.0);
    if (w2sCheck[2] && w2sCheck[3]) ImGui::GetBackgroundDrawList()->AddLine(screenVertices[2], screenVertices[3], ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 1.0);
    if (w2sCheck[3] && w2sCheck[0]) ImGui::GetBackgroundDrawList()->AddLine(screenVertices[3], screenVertices[0], ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 1.0);

    if (w2sCheck[4] && w2sCheck[5]) ImGui::GetBackgroundDrawList()->AddLine(screenVertices[4], screenVertices[5], ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 1.0);
    if (w2sCheck[5] && w2sCheck[6]) ImGui::GetBackgroundDrawList()->AddLine(screenVertices[5], screenVertices[6], ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 1.0);
    if (w2sCheck[6] && w2sCheck[7]) ImGui::GetBackgroundDrawList()->AddLine(screenVertices[6], screenVertices[7], ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 1.0);
    if (w2sCheck[7] && w2sCheck[4]) ImGui::GetBackgroundDrawList()->AddLine(screenVertices[7], screenVertices[4], ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 1.0);

    if (w2sCheck[0] && w2sCheck[4]) ImGui::GetBackgroundDrawList()->AddLine(screenVertices[0], screenVertices[4], ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 1.0);
    if (w2sCheck[1] && w2sCheck[5]) ImGui::GetBackgroundDrawList()->AddLine(screenVertices[1], screenVertices[5], ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 1.0);
    if (w2sCheck[2] && w2sCheck[6]) ImGui::GetBackgroundDrawList()->AddLine(screenVertices[2], screenVertices[6], ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 1.0);
    if (w2sCheck[3] && w2sCheck[7]) ImGui::GetBackgroundDrawList()->AddLine(screenVertices[3], screenVertices[7], ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 1.0);
   
}


void DrawBox(float X, float Y, float W, float H, ImColor Color, float curve, float thickness)
{
	ImDrawList* draw_list = ImGui::GetForegroundDrawList();
    // Vẽ box trong suốt
	draw_list->AddRect(ImVec2(X + 1, Y + 1), ImVec2(X + W - 1, Y + H - 1), Color);
	// Vẽ viền box
	draw_list->AddRect(ImVec2(X, Y), ImVec2(X + W, Y + H), Color, curve, thickness);
}

void drawRectFilledWithPos(ImVec2 pos, ImVec2 size, ImColor color)
{
    ImGui::GetBackgroundDrawList()->AddRectFilled(pos, ImVec2(pos.x + size.x, pos.y + size.y), color, 0, 0);
}

void DrawText2(ImFont* _espFont, float fontSize, ImVec2 position, ImColor Color, const char* text, ImColor colorFilled)
{
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(position.x - 3, position.y - 3), ImVec2(position.x + _espFont->CalcTextSizeA(fontSize, MAXFLOAT, 0.0f, text).x + 3, position.y + 12), colorFilled, 0, 0);
    ImDrawList* draw_list = ImGui::GetForegroundDrawList();
    draw_list->AddText(NULL, fontSize, position, Color, text);
}



void DrawEsp() {
    ImDrawList* drawList = ImGui::GetBackgroundDrawList(); // Lấy đối tượng để vẽ trên màn hình

    int numberOfPlayersAround = 0;

    bool hasPlayers = !players.empty(); // Kiểm tra xem có player nào trong danh sách players không
    bool anyPlayerInFOV = false; // Biến kiểm tra xem có player nào trong tầm nhìn không
    ImVec2 screenCenter(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2); // Tính tọa độ trung tâm màn hình
    if (ESPEnable && hasPlayers) { // Nếu ESP được bật và có players
        for (int i = 0; i < players.size(); i++) { // Duyệt qua danh sách players
            auto* player = players[i]; // Lấy player hiện tại
            if (!player || !get_main() || IsTeammate(player)) { // Nếu player không hợp lệ, không có camera chính hoặc là đồng đội thì bỏ qua
                continue;
            }
numberOfPlayersAround++;
            auto pos = get_position(get_transform(player)); // Lấy vị trí của player
            auto viewpos = get_position(get_transform(get_main())); // Lấy vị trí của camera chính
            bool w2sCheck = false; // Biến kiểm tra xem player có nằm trong tầm nhìn không

            world2screen_c(pos + Vector3(0, 0.75f, 0), w2sCheck); // Chuyển đổi vị trí của player từ tọa độ thế giới sang tọa độ màn hình
            Vector3 headPos = GetPlayerLocation(player) + Vector3(0, 1.6f, 0); // Lấy vị trí đầu của player
            Vector3 footPos = GetPlayerLocation(player) + Vector3(0, 0.0f, 0); // Lấy vị trí chân của player

            ImVec2 top_pos = world2screen_i(headPos); // Chuyển đổi vị trí đầu sang tọa độ màn hình
            ImVec2 bot_pos = world2screen_i(footPos); // Chuyển đổi vị trí chân sang tọa độ màn hình
            float boxHeight = fabs(top_pos.y - bot_pos.y); // Tính chiều cao của box ESP
            float boxWidth = boxHeight * 0.65f; // Tính chiều rộng của box ESP

            float segmentWidth = boxWidth / 4.0f; // Tính chiều rộng của mỗi đoạn trong box ESP
            float segmentHeight = boxHeight / 4.0f; // Tính chiều cao của mỗi đoạn trong box ESP

            ImVec2 top_left(top_pos.x - boxWidth / 2.0f, top_pos.y); // Tính tọa độ góc trên bên trái của box ESP
            ImVec2 top_right(top_pos.x + boxWidth / 2.0f, top_pos.y); // Tính tọa độ góc trên bên phải của box ESP
            ImVec2 bottom_left(bot_pos.x - boxWidth / 2.0f, bot_pos.y); // Tính tọa độ góc dưới bên trái của box ESP
            ImVec2 bottom_right(bot_pos.x + boxWidth / 2.0f, bot_pos.y); // Tính tọa độ góc dưới bên phải của box ESP

            
            float circleRadius = 90.0f; // Bán kính của vòng tròn FOV
            ImVec2 enemyPos = world2screen_i(GetPlayerLocation(player)); // Chuyển đổi vị trí của player sang tọa độ màn hình
            float angle = atan2f(enemyPos.y - screenCenter.y, enemyPos.x - screenCenter.x); // Tính góc giữa player và tâm màn hình

            float arrowTipX = screenCenter.x + circleRadius * cos(angle); // Tính tọa độ mũi tên ESP
            float arrowTipY = screenCenter.y + circleRadius * sin(angle); // Tính tọa độ mũi tên ESP

            ImVec2 botPos = world2screen_i(pos + Vector3(0, -0.15f, 0)); // Tính tọa độ chân của player
            ImVec2 topPos = world2screen_i(pos + Vector3(0, 1.9f, 0)); // Tính tọa độ đầu của player

            ImVec2 playerMidPos = ImVec2(
                (topPos.x + botPos.x) / 2, // Tính tọa độ trung bình theo chiều ngang
                (topPos.y + botPos.y) / 2 // Tính tọa độ trung bình theo chiều dọc
            );
            float deltaX = playerMidPos.x - screenCenter.x; // Tính khoảng cách theo chiều ngang giữa player và tâm màn hình
            float deltaY = playerMidPos.y - screenCenter.y; // Tính khoảng cách theo chiều dọc giữa player và tâm màn hình
            float distanceFromCenter = sqrt(deltaX * deltaX + deltaY * deltaY); // Tính khoảng cách giữa player và tâm màn hình
            


            float baseAngle1 = angle + (5.0f * M_PI / 6.0f); // Tính góc cơ sở 1 cho mũi tên ESP
            float baseAngle2 = angle - (5.0f * M_PI / 6.0f); // Tính góc cơ sở 2 cho mũi tên ESP

            float arrowBaseX1 = arrowTipX + 10.0f * cos(baseAngle1); // Tính tọa độ đáy mũi tên ESP 1
            float arrowBaseY1 = arrowTipY + 10.0f * sin(baseAngle1); // Tính tọa độ đáy mũi tên ESP 1
            float arrowBaseX2 = arrowTipX + 10.0f * cos(baseAngle2); // Tính tọa độ đáy mũi tên ESP 2
            float arrowBaseY2 = arrowTipY + 10.0f * sin(baseAngle2); // Tính tọa độ đáy mũi tên ESP 2

            int health = get_CurHP(player); // Lấy máu hiện tại của player
            int maxhp = get_MaxHP(player); // Lấy máu tối đa của player
            float HPBarWidth = 80.0f; // Chiều rộng của thanh máu
            float HPBarHeight = 4.5f; // Chiều cao của thanh máu
            ImColor healthColor; // Màu của thanh máu
            ImVec2 HPBarCenter(top_pos.x, top_pos.y - 25); // Tọa độ trung tâm của thanh máu
            ImVec2 HPBarTopLeft(HPBarCenter.x - HPBarWidth / 2, HPBarCenter.y - HPBarHeight / 2); // Tọa độ góc trên bên trái của thanh máu
            ImVec2 HPBarBottomRight(HPBarTopLeft.x + (HPBarWidth * health / maxhp), HPBarTopLeft.y + HPBarHeight); // Tọa độ góc dưới bên phải của thanh máu
            float rounding = HPBarHeight / 4.0f; // Độ bo tròn của thanh máu
            float lineBox = 0.9f; // Độ dày của đường viền box ESP
            ImVec4 boxColor, lineColor; // Màu của box ESP và đường viền

            if (get_IsDieing(player)) { // Nếu player đang chết
                boxColor = ImColor(255, 0, 0); // Màu đỏ
                lineColor = ImColor(255, 0, 0); // Màu đỏ
            }
            else { // Nếu player không chết
                lineColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f); // Màu trắng
                boxColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f); // Màu trắng 
            }

            Vector3 playerLocation = GetPlayerLocation(player); // Lấy vị trí của player
            Vector3 cameraLocation = GetPlayerLocation(get_main()); // Lấy vị trí của camera chính

            // Tính khoảng cách giữa player và camera chính
            float distance = Vector3::Distance(playerLocation, cameraLocation);

            if (distance > 400) { // Nếu khoảng cách lớn hơn 400 thì bỏ qua
                continue;
            }
            
            if (ESPArrow) { // Nếu mũi tên ESP được bật

                float distanceToEnemy = sqrtf(powf(enemyPos.x - screenCenter.x, 2) + powf(enemyPos.y - screenCenter.y, 2)); // Tính khoảng cách giữa player và tâm màn hình
                ImColor dotColor = IsClientBot(player) ? ImColor(0, 255, 0) : (getPlayerNickname(player) != "" ? ImColor(255, 0, 0) : ImColor(255, 0, 0)); // Xác định màu của chấm ESP
                drawList->AddTriangleFilled(ImVec2(arrowTipX, arrowTipY), ImVec2(arrowBaseX1, arrowBaseY1), ImVec2(arrowBaseX2, arrowBaseY2), ImColor(255, 0, 0)); // Vẽ chấm ESP
            }

            if (distance > sliderDistanceValue) { // Nếu khoảng cách lớn hơn sliderDistanceValue thì bỏ qua
                continue;
            }
            auto pmtXtop = top_pos.x; // Tọa độ x của đỉnh box ESP
            auto pmtXbottom = bot_pos.x; // Tọa độ x của đáy box ESP
            if (top_pos.x > bot_pos.x) { // Nếu tọa độ x của đỉnh lớn hơn tọa độ x của đáy
                pmtXtop = bot_pos.x; // Hoán đổi tọa độ
                pmtXbottom = top_pos.x; // Hoán đổi tọa độ
            }

            float positionCalc = fabs((top_pos.y - bot_pos.y) * (0.0092f / 0.019f) / 2); // Tính toán vị trí của box ESP
            ImRect rect(ImVec2(pmtXtop - positionCalc, top_pos.y), ImVec2(pmtXbottom + positionCalc, bot_pos.y)); // Tạo hình chữ nhật cho box ESP
            if (w2sCheck) { // Nếu player nằm trong tầm nhìn
if (ESPLine) { // Nếu ESP Line được bật

                    // Kiểm tra nếu mục tiêu là kẻ địch và đang trong tầm nhìn
                    ImColor lineColor = (targetEnemy != nullptr && targetEnemy == player && IsVisible(targetEnemy)) 
                                        ? ImColor(255, 255, 255) // xanh nếu kẻ địch trong tầm nhìn
                                        : ImColor(255, 255, 255); // Màu mặc định (hoặc thay đổi màu mặc định tại đây)

                            ImGui::GetBackgroundDrawList()->AddLine({ImGui::GetIO().DisplaySize.x/2, 0}, {rect.GetCenter().x, rect.Min.y}, ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 0.9);
                }



 if (ESPBox) { // Nếu ESP Box được bật
                    ImColor boxColor = ImColor(255, 255, 255); // Màu trắng mặc định

                    if (targetEnemy != nullptr && targetEnemy == player && IsVisible(targetEnemy)) {
                        boxColor = ImColor(255, 255, 255); // Đổi thành màu xanh nếu là mục tiêu Aimbot và đang nhìn thấy
                    }
                    float cornerSize = boxHeight / 5.0f; // Kích thước góc bo
                    drawList->AddLine(top_left, top_left + ImVec2(cornerSize, 0), ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 0.7);
                    drawList->AddLine(top_left, top_left + ImVec2(0, cornerSize), ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 0.7);
                    drawList->AddLine(top_right, top_right + ImVec2(-cornerSize, 0), ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 0.7);
                    drawList->AddLine(top_right, top_right + ImVec2(0, cornerSize), ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 0.7);
                    drawList->AddLine(bottom_left, bottom_left + ImVec2(cornerSize, 0), ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 0.7);
                    drawList->AddLine(bottom_left, bottom_left + ImVec2(0, -cornerSize), ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 0.7);
                    drawList->AddLine(bottom_right, bottom_right + ImVec2(-cornerSize, 0), ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 0.7);
                    drawList->AddLine(bottom_right, bottom_right + ImVec2(0, -cornerSize), ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 0.7);
                }


                if (get_isLiving(player)) { // Nếu player còn sống
                    if (get_IsDieing(player)) { // Nếu player đang chết
                        healthColor = ImColor(255, 0, 0); // Màu đỏ
                    }
                    else if (health >= 140) { // Nếu máu lớn hơn hoặc bằng 140
                        healthColor = ImColor(0, 255, 0); // Màu xanh lá
                    }
                    else if (health >= 80 && health < 140) { // Nếu máu từ 80 đến 139
                        healthColor = ImColor(0, 0, 255); // Màu vàng
                    }
                    else { // Nếu máu nhỏ hơn 80
                        healthColor = ImColor(255, 0, 0); // Màu đỏ
                    }
                                        if (ESPName) {
    auto playerName = getPlayerNickname(player);
    // Dời vị trí y xuống thêm 2 pixel
    ImVec2 namePosition((rect.Min.x + rect.Max.x) * 0.5f - 30, rect.Min.y - 7);

    ImVec2 textSize = ImGui::CalcTextSize(playerName.c_str());
ImVec2 backgroundMin(namePosition.x - 0, namePosition.y - 12); // Giảm giá trị -17 thành -12
ImVec2 backgroundMax(backgroundMin.x + textSize.x + 17, backgroundMin.y + textSize.y + 2); // Giảm chiều cao từ +5 xuống +2


    std::string playerNumber = std::to_string(numberOfPlayersAround) + "   ";
    std::string playerNameWithNumber = playerNumber + playerName;

    //float squareSize = textSize.y + 4;
    //ImVec2 squareMin(backgroundMin.x, backgroundMin.y);
    //ImVec2 squareMax(squareMin.x + squareSize, squareMin.y + squareSize);

    float squareSize = textSize.y - 2; // Giảm chiều cao hình vuông
ImVec2 squareMin(backgroundMin.x, backgroundMin.y + 1); // Dời khung lên trên một chút
ImVec2 squareMax(squareMin.x + squareSize, squareMin.y + squareSize);

ImGui::GetBackgroundDrawList()->AddRectFilled(squareMin, squareMax, ImColor(0, 255, 0, 200), 0.0f);
    ImGui::GetBackgroundDrawList()->AddRectFilled(backgroundMin, backgroundMax, ImColor(0, 0, 0, 100), 5.0f);
    ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), 12.0f, ImVec2(backgroundMin.x + 7, backgroundMin.y + 2), ImColor(255, 255, 0, 225), playerNameWithNumber.c_str());

}
                if (ESP2DBox) {
                    ImColor boxColor = ImColor(0, 255, 0);
                    

                    float height =  abs(enemyPos.y - top_pos.y);
                    float width = height * 0.55f;
                    DrawBox(top_pos.x - (width * 0.4),  top_pos.y, width, height, ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 0.9, 0.9);
                }

                // Calculate the total width of the ESP block
                float maxTextWidth = 0.0f;


if (ESPHealth) {
    float playerHealth = static_cast<float>(get_CurHP(player));
    float healthPercentage = playerHealth / 200.0f;  
    float healthBarHeight = rect.Max.y - rect.Min.y;  

    ImVec2 healthBarPos(rect.Min.x - 10 + 7, rect.Min.y);


    float healthFilledHeight = healthBarHeight * healthPercentage;
    ImU32 healthColor = ImColor(0, 255, 0);  
    if (healthPercentage <= 0.3f) {
        healthColor = ImColor(255, 0, 0);  
    } else if (healthPercentage <= 0.6f) {
        healthColor = ImColor(255, 255, 0);  
    }

    float healthBarWidth = 6.0f;

    ImGui::GetBackgroundDrawList()->AddRectFilled(healthBarPos, ImVec2(healthBarPos.x + healthBarWidth, healthBarPos.y + healthFilledHeight), healthColor, 0.0f);

    ImGui::GetBackgroundDrawList()->AddRect(healthBarPos, ImVec2(healthBarPos.x + healthBarWidth, healthBarPos.y + healthBarHeight), ImColor(0, 0, 0), 0.0f, 0, 1.0f);
}


if(ESP3DBox){
    Draw3DBox(pos, player);
}
                    if (ESPDistance) { // Nếu ESP Distance được bật
                        char distanceText[32];
                        sprintf(distanceText, "[%.0f M]", distance);
                        ImVec2 textSize = ImGui::GetFont()->CalcTextSizeA(ImGui::GetFontSize() * 0.50f, FLT_MAX, 0.0f, distanceText);
                        ImVec2 textPosition = ImVec2(HPBarTopLeft.x + 1, HPBarTopLeft.y - textSize.y / 1); // Vị trí khoảng cách (bên cạnh máu)
                        drawList->AddText(ImGui::GetFont(), ImGui::GetFontSize() * 0.55f, textPosition, ImColor(0, 245, 255), distanceText);
                    }
                }
            }    
        }

        if (ESPCount) {
            ImVec2 numberPosition(ImGui::GetIO().DisplaySize.x / 2.05f, 20);
            ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), 40.0f, numberPosition, ImColor(255, 0, 0), std::to_string(numberOfPlayersAround).c_str());
        }
    }

    if (aim180 && hasPlayers) { // Nếu Aimbot được bật và Enable được bật
        for (int i = 0; i < players.size(); i++) { // Duyệt qua danh sách players
            auto* player = players[i]; // Lấy player hiện tại
            if (!player || !get_main() || IsTeammate(player)) { // Nếu player không hợp lệ, không có camera chính hoặc là đồng đội thì bỏ qua
                continue;
            }
        auto pos = get_position(get_transform(player)); // Lấy vị trí của player
            auto viewpos = get_position(get_transform(get_main())); // Lấy vị trí của camera chính
            bool w2sCheck = false; // Biến kiểm tra xem player có nằm trong tầm nhìn không

            world2screen_c(pos + Vector3(0, 0.75f, 0), w2sCheck); // Chuyển đổi vị trí của player từ tọa độ thế giới sang tọa độ màn hình
            Vector3 headPos = GetPlayerLocation(player) + Vector3(0, 1.6f, 0); // Lấy vị trí đầu của player
            Vector3 footPos = GetPlayerLocation(player) + Vector3(0, 0.0f, 0); // Lấy vị trí chân của player

            ImVec2 top_pos = world2screen_i(headPos); // Chuyển đổi vị trí đầu sang tọa độ màn hình
            ImVec2 bot_pos = world2screen_i(footPos); // Chuyển đổi vị trí chân sang tọa độ màn hình
            float boxHeight = fabs(top_pos.y - bot_pos.y); // Tính chiều cao của box ESP
            float boxWidth = boxHeight * 0.8f; // Tính chiều rộng của box ESP

            float segmentWidth = boxWidth / 4.0f; // Tính chiều rộng của mỗi đoạn trong box ESP
            float segmentHeight = boxHeight / 4.0f; // Tính chiều cao của mỗi đoạn trong box ESP

            ImVec2 top_left(top_pos.x - boxWidth / 2.0f, top_pos.y); // Tính tọa độ góc trên bên trái của box ESP
            ImVec2 top_right(top_pos.x + boxWidth / 2.0f, top_pos.y); // Tính tọa độ góc trên bên phải của box ESP
            ImVec2 bottom_left(bot_pos.x - boxWidth / 2.0f, bot_pos.y); // Tính tọa độ góc dưới bên trái của box ESP
            ImVec2 bottom_right(bot_pos.x + boxWidth / 2.0f, bot_pos.y); // Tính tọa độ góc dưới bên phải của box ESP

            
            float circleRadius = 90.0f; // Bán kính của vòng tròn FOV
            ImVec2 enemyPos = world2screen_i(GetPlayerLocation(player)); // Chuyển đổi vị trí của player sang tọa độ màn hình
            float angle = atan2f(enemyPos.y - screenCenter.y, enemyPos.x - screenCenter.x); // Tính góc giữa player và tâm màn hình

            float arrowTipX = screenCenter.x + circleRadius * cos(angle); // Tính tọa độ mũi tên ESP
            float arrowTipY = screenCenter.y + circleRadius * sin(angle); // Tính tọa độ mũi tên ESP

            ImVec2 botPos = world2screen_i(pos + Vector3(0, -0.15f, 0)); // Tính tọa độ chân của player
            ImVec2 topPos = world2screen_i(pos + Vector3(0, 1.9f, 0)); // Tính tọa độ đầu của player

            ImVec2 playerMidPos = ImVec2(
                (topPos.x + botPos.x) / 2, // Tính tọa độ trung bình theo chiều ngang
                (topPos.y + botPos.y) / 2 // Tính tọa độ trung bình theo chiều dọc
            );
            float deltaX = playerMidPos.x - screenCenter.x; // Tính khoảng cách theo chiều ngang giữa player và tâm màn hình
            float deltaY = playerMidPos.y - screenCenter.y; // Tính khoảng cách theo chiều dọc giữa player và tâm màn hình
            float distanceFromCenter = sqrt(deltaX * deltaX + deltaY * deltaY); // Tính khoảng cách giữa player và tâm màn hình
            


            float baseAngle1 = angle + (5.0f * M_PI / 6.0f); // Tính góc cơ sở 1 cho mũi tên ESP
            float baseAngle2 = angle - (5.0f * M_PI / 6.0f); // Tính góc cơ sở 2 cho mũi tên ESP

            float arrowBaseX1 = arrowTipX + 10.0f * cos(baseAngle1); // Tính tọa độ đáy mũi tên ESP 1
            float arrowBaseY1 = arrowTipY + 10.0f * sin(baseAngle1); // Tính tọa độ đáy mũi tên ESP 1
            float arrowBaseX2 = arrowTipX + 10.0f * cos(baseAngle2); // Tính tọa độ đáy mũi tên ESP 2
            float arrowBaseY2 = arrowTipY + 10.0f * sin(baseAngle2); // Tính tọa độ đáy mũi tên ESP 2

            int health = get_CurHP(player); // Lấy máu hiện tại của player
            int maxhp = get_MaxHP(player); // Lấy máu tối đa của player
            float HPBarWidth = 80.0f; // Chiều rộng của thanh máu
            float HPBarHeight = 5.5f; // Chiều cao của thanh máu
            ImColor healthColor; // Màu của thanh máu
            ImVec2 HPBarCenter(top_pos.x, top_pos.y - 25); // Tọa độ trung tâm của thanh máu
            ImVec2 HPBarTopLeft(HPBarCenter.x - HPBarWidth / 2, HPBarCenter.y - HPBarHeight / 2); // Tọa độ góc trên bên trái của thanh máu
            ImVec2 HPBarBottomRight(HPBarTopLeft.x + (HPBarWidth * health / maxhp), HPBarTopLeft.y + HPBarHeight); // Tọa độ góc dưới bên phải của thanh máu
            float rounding = HPBarHeight / 2.0f; // Độ bo tròn của thanh máu
            float lineBox = 0.9f; // Độ dày của đường viền box ESP
            ImVec4 boxColor, lineColor; // Màu của box ESP và đường viền

            if (get_IsDieing(player)) { // Nếu player đang chết
                boxColor = ImColor(255, 0, 0); // Màu cam
                lineColor = ImColor(255, 0, 0); // Màu cam
            }
            else { // Nếu player không chết
                lineColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f); // Màu trắng
                boxColor = ImVec4(0.0f, 1.0f, 0.0f, 1.0f); // Màu xanh lá
            }

            Vector3 playerLocation = GetPlayerLocation(player); // Lấy vị trí của player
            Vector3 cameraLocation = GetPlayerLocation(get_main()); // Lấy vị trí của camera chính
    
        void* CurrentMatch = Curent_Match();
        void* LocalPlayer = GetLocalPlayer(CurrentMatch);

        float closestDistance = FLT_MAX;
        void* closestEnemy = nullptr;

        if (Fov) {
            drawList->AddCircle(screenCenter, AimbotFOV, ImColor(125, 38, 205), 0, 0.5f);
        }

        if (LocalPlayer != NULL && CurrentMatch != NULL) {
            // Kiểm tra thời gian để thay đổi mục tiêu
            float currentTime = ImGui::GetTime();
            if (currentTime - lastTargetChangeTime >= 4.0f) {
                targetEnemy = nullptr;
                lastTargetChangeTime = currentTime;
            }

            if (targetEnemy != nullptr && get_isLiving(targetEnemy) && !IsTeammate(targetEnemy) && !get_IsDieing(targetEnemy)) {
            // Kiểm tra FOV trước, sau đó mới kiểm tra tầm nhìn
            if (IsTargetInPlayerView(LocalPlayer, targetEnemy)) {
                if (IsVisible(targetEnemy) && Vector3::Distance(GetHeadPosition(targetEnemy), CameraMain(LocalPlayer)) <= AimDis) {
                    closestEnemy = targetEnemy;
                } else {
                    // Mục tiêu hiện tại không còn nhìn thấy, reset và tìm kiếm mục tiêu mới ngay lập tức
                    targetEnemy = nullptr;
                    lastTargetChangeTime = 0.0f; 
                }
            } else {
                // Mục tiêu hiện tại ra khỏi FOV, reset và tìm kiếm mục tiêu mới ngay lập tức
                targetEnemy = nullptr;
                lastTargetChangeTime = 0.0f;
            }
        }

        if (closestEnemy == nullptr) {
            // Tìm kiếm mục tiêu mới, kiểm tra FOV trước, sau đó mới kiểm tra tầm nhìn
            for (auto& enemy : players) {
                if (enemy != NULL && !IsTeammate(enemy) && !get_IsDieing(enemy) && IsTargetInPlayerView(LocalPlayer, enemy)) {
                    if (IsVisible(enemy)) {
                        float distance = Vector3::Distance(GetHeadPosition(enemy), CameraMain(LocalPlayer));
                        if (distance <= AimDis && distance < closestDistance) {
                            closestDistance = distance;
                            closestEnemy = enemy;
                        }
                    }
                }
            }
        }

            if (closestEnemy != NULL) { // Nếu tìm thấy enemy gần nhất
                targetEnemy = closestEnemy; // Lưu trữ enemy đang được nhắm
                Vector3 EnemyLocation = GetHeadPosition(closestEnemy); // Lấy vị trí đầu của enemy
                Vector3 PlayerLocation = CameraMain(LocalPlayer); // Lấy vị trí camera của bạn
                Quaternion PlayerLook = GetRotationToLocation(EnemyLocation, 0.1f, PlayerLocation); // Tính toán góc nhìn để nhắm vào enemy
                bool IsScopeOn = get_IsSighting(LocalPlayer); // Kiểm tra xem bạn có đang ngắm không
                bool IsFiring = get_IsFiring(LocalPlayer); // Kiểm tra xem bạn có đang bắn không

                if (AimWhen == 0) { // Nếu AimWhen được đặt thành 0 (luôn luôn)
                    set_aim(LocalPlayer, PlayerLook); // Set aim vào enemy
                }
                else if (AimWhen == 1 && IsFiring) { // Nếu AimWhen được đặt thành 1 (khi bắn) và bạn đang bắn
                    set_aim(LocalPlayer, PlayerLook); // Set aim vào enemy
                }
                else if (AimWhen == 2 && IsScopeOn) { // Nếu AimWhen được đặt thành 2 (khi ngắm) và bạn đang ngắm
                    set_aim(LocalPlayer, PlayerLook); // Set aim vào enemy
                }
            } else {
                targetEnemy = nullptr; // Reset targetEnemy nếu không tìm thấy enemy phù hợp
            }
        }
    }
         
    } else {
        players.clear(); // Xóa danh sách players nếu Aimbot hoặc Enable bị tắt
        targetEnemy = nullptr; // Reset targetEnemy nếu Aimbot hoặc Enable bị tắt
    }
}

#endif  // ESP_H