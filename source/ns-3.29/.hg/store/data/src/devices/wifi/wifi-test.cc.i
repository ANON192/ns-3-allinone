        �  I      
B���������w��-��v�'��/S�k��            (�/�`I �(y' ϸ��-'��P5�NI�:�_�`c�c��`Z�����an l n 5���ձ�K廮�w^��_����a�>^p#�����k�דX���_%����tR�t�h{�����^_c[�a=�����=F����].B�]*C5d4��"���_	<y���n�g�F��ļPcIڕd���i0v�t����^i�n�����S<- п����>��N<Z���\	���4�1��%冯Ξ��j��~��6�d��zV��k���~8P�1и�(�S��ʞ[��$��{�=�l�.��Ʈ)5�o'�k"I�)�ku���5֘�ÙLQ��1���(�%�k��.<Q(��%�k�'�����J�v�{-����c6�"`W�E�e�3vW��p��;e����/*W�����h�oLWt��'���F��pM�HR��ӓy�<��	�WV��nF��ɔOy$��1�8 vD���/6�Vq��zv�#�ݨ��bhh @  @  B��2 3-I�S�df���J` 3�_��i;9犸$T����Z3��)�K�����L����;.�"ȥ�j����b�w��7b����� F6b-~|�[�h���#��R�n� P���}J�!fEL���n������Lb�	lf��=�2��X��$[.Y�s�e�5	�|Ƶ�>*�T =J�%tQf���gkt���F(�D���)�N�pX���rDbc�������XV�F`�#3P�p<�9�%�ПIA���?q�q��D�g!� MI�H�����4V`�k���o�2<ٸ���>�@|LAts#��	������|ʸ���.���}q�T�Z2v���i�Ai
#���݁��O���#q���e7��w��Ի��ԯ����l��ч~0aP+\``O�7�^��TF��`�d�8��j�<�+���3>�,S�����|�3u�r���%dqF{%8�%��,�/�1%    �     (  P      
C    ����p����2�nTkr�@�2�                   static WifiTest g_wifiTest;
         0  N     f   ����O�ʹ���{$�����;�y�              �  �   $  Simulator::Stop (Seconds (10.0));
    E     f  W     0   ����)m��u.�{/I�̂Y�               j   �   #include "yans-wifi-phy.h"
  �  �   3  Ptr<WifiPhy> phy = CreateObject<YansWifiPhy> ();
    �     �  �     5   ����[�t=]�Y����u��8����            (�/� �= �#'�1�`�t����ZR�=5�(���(L'�e4.�.�j*�yK�4}-�Z��%�{P�;�'P�%r�F[rb��x�Fl�dl�3�5� "�,����ۍ� �t� �&�8c�a�J��K���_X�6�/�3�d|���8�L�W�7� K}c��FF� �0/SQ    [      "     H   ����q��-@s�"�c�S��[qP[            (�/�`� � R�..�9	�K AeD	�9!ْ$d)h���BH��9��Z�ܔS��ը$Ԕ�=�����Vs��Du��m�#,]:� =Փ�"�-$8ɚ��VOR�z����+�C�������a;IS(:��]b5drft2EIe��K>��E�FJ�b��a4l'���(�|2��(�#z75�� BKPX�a����(z�*YX ��W3qcF7�j54��2��P�	g|,8�9"    ]     u  I     �   �������p�c�����	��w��            (�/� ~e �   ##include "yans-error-rate-model.h"
  �  :   C  Ptr<ERateM>  = CreateObject<Yans();
 �B���LcR>8"    �     �  h     �   ����&���腻�[��Ɍ���4�k�            (�/� �� �  2  Y   2#include "ns3/constant-position-mobility-model.h"
  �  �   `  Ptr<CPMM>  = CreateObject();
 Zq5�7��\�+Ǣ�(    X      �     �   �����	�i}���S�Р6�<c�N�            (�/�`C5 �#k&�: �/�H�޷Bz$v�TA.��l�6n�>�xMb Y d ��Ǉ��ͥ�OӚ�ߝ�)�{3#gw����DU�Q�x��ql�exn:	���X4	r� �yu�,�%�3_X�i
-d�.@�������i$  ŻbX����9������[�gR��/�UFnE6�g������(�έ�ҸK�1����7�J�&O�����s�X߼�8�ܧld���ó)�V�b;�o{��諼0(�כ}��k�k�RY*�&�B]�T��j"r˂�\T�S�rQ�a�(����h�oΧy�;��b�Un͚K��2U�D�e�e������E���gd�㭓�28�o�aO���|aʭ��|1Y�?!2p@�����O�M�ß���Z{�����0�H���m��?-�5���D	ߦ���" 0���4 ps�&�L,��]���|Xpk��;-;`�񓞖�M�X���,['�w���4h��S?�ŀ��!���]�E��)�H\,    	h     �  5     6   ����t<ν"���Z��`+�
�~�            (�/� �� �   /#include "dca-txop.h"
ns3/pointer  � 1  Ptr<DcaTxop> queue = CreateObject();� 6  mac->SetAttribute("", PValue ());

 ^c� ��{��0�~�!<�'�.    
     f  8   	  p   	����/�_�Ψ�ב'lIe�Yx�            (�/� �� �  �   =  s   5  mac->ConfigureStandard (WIFI_PHY_STANDARD_80211a);
  	�phy A,�1�    
n    �     
  �   
�������ׂ����k����?r��            (�/�`O5 v\<@kx��/]�4���~z$jR��5rȇ�O�����s3���� �t��|�����C&&�J J M  �[̸�F���?a��dW�!�yWm�8��Őn�S<9�Q؆ �ɖSB��WA��K�8�<�F�}���H�8l����F�u$��&�Cb���r�w��=D��a'��9@�&����bKj����6��m�aK�U04�1�ECq�XX�Ԝ���P�O,�dnM��Z�Y�����GG
T��� �p��g�dd�M�6�vQy�֫
�_�~y9�����}��O�k�o���Ԧ��'�~�%�]QoJj:�Q����3����(r�v�{3�r~]�_��u�+�* ��6pY��
���A&�	$ E p�����Er8�
D @��D ��M������B��.�	�#�S�Rg\�i����a�j[e�bȻ7u���-����6��F�|#��kI=��{f!��9{�.��T8й=d��[���0ID�
�n�Q������'��6�I��>��H�w��$�Y�	28b�����%��ITb@�tW���jc�Q��qE61U��b@����MM+Ew��fU�&�k��A�M�.�#T-���"�ƈ�����!E�s����W�Q�S�s�߬���
��"<�]�         %  .        �����f]j�wy]���a��U��M              �  �     Simulator::Destroy ();
    C     L  6     8   ��������V!�?��n
�3&�            (�/� ] �  �     Q#include "ns3/propagation-delay-model.h"
loss Km����    �    �  �     �   �������Ɇt!NΚ�ϼ8�)ј            (�/�`'} f�=2p�� �f�������ٙB:%��Z���1��ɢi#�&�Ҡ�Q�V��<w. 0 2 �1���i��٤�.sȯ�וY�h��6X:o���[img����D#-�m^.^{��#� ���f�D�:��pZ��4v����	 ���C�vr1��ٷy���C���q�һ�G�T؂�]��"Qa�U]�EqlH0E#mN�]+�蚖�ض�]��~<&ؐ�'!5��F+�q�ң('� �z��< `�a��  <���:�] (p��Ԫ'D~)�B���	��A�;�V��[P�Z�a;F��X � n
B�,�8��aA|�Z�A0$X�b��&A� � �5���B���,l0�,�E�E 3v^�N�~��g[y��ȸ�nE�q�D0�    (    �  &      	   ����������b� 2��fl���            (�/�`��$ ��5 M�   $ !���"�Ma�Bԟ�of�ak��hN���,��(����G�@� � � ����}���TGziP/�/sd�\��r��6A)�(�8�ۭ��;����8�C�Ylڧ_ۙMC[�5�'4�][S��ʭe~�A��8��|�I^��my�Nm��(t��r>h{�m�8�Va�  �<��L*�K����|�'���2M�^ƶLZ����Lf\z<b�V�m	��N58!�E\;��9ׁ�����w��49��"ƚ�Ѫ�H�O�*�w*��#\�,$~wM.x��㩆�Ӕۗ�� czJ��֣���zN�&R#)�����+���si��wȖ��eH1��&	 [ޭ�cu�z�t�l*�a��~i�����K�<Qi��,RK�JLZPˤ�JK1w�N��8 1��LT�K��*.L�TT"T(�c�8�Z]���L:�w��C�NA�t��E�]��w.L�
��g������5  ,�Z�m��$�^ɂJ��$�(3����}T�.�$����Ia[�m�/h�ak����HzI�U�8�>�I�aSbC}��R� �e�)Ɔ5Z1�[��-�^��&v2�c��N�倳n�k���C3#!  %  �Bf�@By�0�"Ȑ�d �@DS@�bA΂L6�4`�����H���(��u
,a�+� W#�-����"����(y��2P�8E�#�.��%��
		7�׉^�*a%G"#7�9qF�J�ʎ�T)3��R������1-��G�V�fi#5�K��9!(W�u d�!Y�|p���;J��Lt{�R���V��`���ưp�y�ͪ��U���y1�A+u���z��s5&"S�f��ɕ�Ȏћl��H9W�\�Ս�e`I��dTZ;�	I��O�폢ߏ+�����p:�bQ�x��0A?�� �7�Р|OǀB���k�)C���N�ģ�W���R�3Cac�b�~\�Z՚�`}�1`�լp�&�Y���[ie8�o���\#���0��Z�����N��D���&M��byjcrn�]�M�	����(
�-�O�4��6:k���soiNf�4���@�%:~.��!��w�j½Ъŧ2B3z��/◃p�<�X��1=o����AC.�7�Í�{�    �     T  %�        ����jK�a��Q�nT
!vF P            (�/� e]   O  w   &  m_mac.SetTypeId ("ns3::ApWifiMac");
  �  �   'Sta V�뢠         �  &�        ��������	�"�.j�_�7�����.            (�/�`�� "M03`m� ��=��SF0�+ަ�"1)EH�*}��O���a���;��!�ZvX�<����G��zhr4�vi��������`YV�6d4t���f6��n�Bȏ�X�vEI�M�B�.��*�ԝ�X�NN6����m=ۡkZ��s�~���p ;��=*(ӟL&ӗL� ~�?$�!��	�������	� ��C�P�=$-�G��L�)#-|��`�c��&X�{�`�         2  &�     v   �����PE6k�C���S�S���Z�              &N  &m   &static WifiTestSuite g_wifiTestSuite;
    D     v  &I     w   �����A�>�үnu>����`��JR�            (�/� �m R� �9��]U`~U�Vϓ��
�'9�edo��Dh	��.�y��G�	��pf�]skf����T)^����`Xu�7x ��9 `} ƪp�N�Q���    �     e  &�     �   ����7)qx�D�OgJX����Ѿ�            (�/� t� $   �  !#   h  propLoss->Set (senderB->GetObject<MobilityModel>(), rxOnly0, true);
 =J�\